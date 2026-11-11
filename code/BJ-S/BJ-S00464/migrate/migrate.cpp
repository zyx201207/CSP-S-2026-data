#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000001],mf[2000001],fe[2000001],ans;
struct St
{
    int val[8000001],lazy[8000001];
    void update (int p)
    {
        val[p]=val[p*2]+val[p*2+1];
    }
    void pushdown (int l,int r,int p)
    {
        if (lazy[p]!=0)
        {
            int mid=(l+r)/2;
            val[p*2]+=lazy[p]*(mid-l+1);
            val[p*2+1]+=lazy[p]*(r-mid);
            lazy[p*2]+=lazy[p];
            lazy[p*2+1]+=lazy[p];
            lazy[p]=0;
        }
    }
    void build (int l,int r,int p)
    {
        if (l==r)
        {
            val[p]=0;
            return;
        }
        int mid=(l+r)/2;
        build(l,mid,p*2);
        build(mid+1,r,p*2+1);
        update(p);
    }
    void add (int l,int r,int L,int R,int p,int k)
    {
        //cout << l << " " << r << " " << L << " " << R << " " << p << " " << k << endl;
        if (R<L)
        {
            return;
        }
        if (R<l||L>r)
        {
            return;
        }
        if (l>=L&&r<=R)
        {
            //cout << k*(r-l+1) << endl;
            val[p]+=k*(r-l+1);
            lazy[p]+=k;
            return;
        }
        int mid=(l+r)/2;
        pushdown(l,r,p);
        if (R<=mid)
        {
            add(l,mid,L,R,p*2,k);
        }
        else if (L>mid)
        {
            add(mid+1,r,L,R,p*2+1,k);
        }
        else
        {
            add(mid+1,r,L,R,p*2+1,k);
            add(l,mid,L,R,p*2,k);
        }
        update(p);
    }
    int query (int l,int r,int L,int R,int p)
    {
        //cout << l << " " << r << " " << L << " " << R << " " << p << endl;
        if (R<L)
        {
            return 0;
        }
        if (R<l||L>r)
        {
            return 0;
        }
        if (l>=L&&r<=R)
        {
            //cout << val[p] << endl;
            return val[p];
        }
        int mid=(l+r)/2;
        pushdown(l,r,p);
        if (R<=mid)
        {
            //cout << query(mid+1,r,L,R,p*2+1) << endl;
            return query(l,mid,L,R,p*2);
        }
        else if (L>mid)
        {
            //cout << query(l,mid,L,R,p*2) << endl;
            return query(mid+1,r,L,R,p*2+1);
        }
        else
        {
            //cout << query(mid+1,r,L,R,p*2+1) << " " << query(l,mid,L,R,p*2) << endl;
            return query(mid+1,r,L,R,p*2+1)+query(l,mid,L,R,p*2);
        }
    }
}st;
signed main ()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while (t--)
    {
        ans=0;
        cin >> n >> d;
        for (int i=1;i<=n;i++)
        {
            cin >> x[i];
        }
        int nj=1;
        for (int i=1;i<=n;i++)
        {
            while (x[i]-x[nj]>d)
            {
                nj++;
            }
            mf[i]=nj;
        }
        for (int i=1;i<n;i++)
        {
            memset(fe,0,sizeof(fe));
            for (int j=0;j<=n;j++)
            {
                if (j==0)
                {
                    st.build(1,n,1);
                    st.add(1,n,i,i,1,1);
                    continue;
                }
                for (int k=n;k>=i;k--)
                {
                    //cout << i << " " << j << " " << k << " " << mf[k] << " " << st.query(1,n,max(mf[k],i),k-1,1) << endl;
                    st.add(1,n,k,k,1,st.query(1,n,max(mf[k],i),k-1,1)-st.query(1,n,k,k,1));
                    //cout << i << " " << j << " " << k << " " << st.query(1,n,k,k,1) << endl;
                    if (st.query(1,n,k,k,1))
                    {
                        if (!fe[k])
                        {
                            fe[k]=st.query(1,n,k,k,1);
                        }
                    }
                }
            }
            for (int j=i;j<=n;j++)
            {
                if (fe[j]==2)
                {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
