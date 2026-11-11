#include<bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)
int n,m;
int a[1000005];
int t[1000005];
int tim[1000005];
int res[1000005];
int num[1000005],laz[1000005];
int ls[1000005],rs[1000005];
int top=1;
void build(int l,int r)
{
    int p=top;
    if(l==r)
    {
        num[p]=1;
        return ;
    }
    ls[p]=++top;
    build(l,mid);
    rs[p]=++top;
    build(mid+1,r);
}
void push_down(int p)
{
    num[ls[p]]=max(num[ls[p]],laz[p]);
    laz[ls[p]]=max(laz[ls[p]],laz[p]);
    num[rs[p]]=max(num[rs[p]],laz[p]);
    laz[rs[p]]=max(laz[rs[p]],laz[p]);
    laz[p]=0;
}
void update(int p,int l,int r,int L,int R,int k)
{
    if(L<=l && r<=R)
    {
        num[p]=max(num[p],k);
        laz[p]=max(laz[p],k);
        return ;
    }
    push_down(p);
    if(L<=mid)
    {
        update(ls[p],l,mid,L,R,k);
    }
    if(R>mid)
    {
        update(rs[p],mid+1,r,L,R,k);
    }
}
int query(int p,int l,int r,int x)
{
    if(l==r)
    {
        return num[p];
    }
    push_down(p);
    if(x<=mid)
    {
        return query(ls[p],l,mid,x);
    }
    if(x>mid)
    {
        return query(rs[p],mid+1,r,x);
    }
}
vector<pair<int,int> > qj[1000005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1])
        {
            flag=0;
        }
    }
    if(n<=300000 && flag==0)
    {
        vector<int> s;
        s.reserve(n);
        for(int k=1;k<=n;k++)
        {
            if(a[k]==a[k-1])
            {
                for(int x:s)
                {
                    res[x]++;
                }
                continue;
            }
            s.clear();
            for(int i=1;i<=m;i++)
            {
                tim[i]=0;
            }
            for(int i=k;i<=n;i++)
            {
                if(a[i]==a[i-1])
                {
                    continue;
                }
                if(tim[a[i]]!=0)
                {
                    while(s.back()!=a[i])
                    {
                        tim[s.back()]=0;
                        s.pop_back();
                    }
                    s.pop_back();
                }
                s.push_back(a[i]);
                tim[a[i]]=i;
            }
            for(int x:s)
            {
                res[x]++;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cout<<res[i]<<" ";
        }
        return 0;
    }
    build(1,n);
    for(int i=1;i<=n;i++)
    {
        if(tim[a[i]]!=0)
        {
            update(1,1,n,tim[a[i]],i-1,tim[a[i]]+1);
        }
        tim[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        int l=query(1,1,n,i),r=i;
        if(l<=r)
        {
            // cout<<i<<" "<<l<<" "<<r<<"\n";
            qj[a[i]].push_back({l,r});
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(qj[i].size()==0)
        {
            cout<<"0 ";
            continue;
        }
        sort(qj[i].begin(),qj[i].end());
        int l=0,r=-1,ans=0;
        for(pair<int,int> x:qj[i])
        {
            if(r>=x.first)
            {
                r=x.second;
            }
            else
            {
                ans+=(r-l+1);
                l=x.first,r=x.second;
            }
        }
        ans+=(r-l+1);
        cout<<ans<<" ";
    }
    return 0;
}