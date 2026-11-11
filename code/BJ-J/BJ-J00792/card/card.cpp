#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans[500005];
int q[500005],cnt,b[500005];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    bool flag=1;
    for(int i=1;i<n;i++)
    {
        if(a[i+1]<a[i])
        {
            flag=0;
            break;
        }
    }
    if(flag)
    {
        for(int i=1;i<=n;i++)
        {
            b[a[i]]++;
        }
        q[1]=b[1];
        for(int i=2;i<=m;i++)
        {
            q[i]=q[i-1]+b[i];
        }
        for(int i=1;i<=m;i++)
        {
            cout<<q[i]<<" ";
        }
        return 0;
    }
    if(n>5000&&m<=2)
    {
        int l1=0,l2=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1&&a[n]==1) l1++;
            if(a[i]==1&&a[n]==2)
            {
                l1++,l2++;
            }
            if(a[i]==2&&a[n]==1)
            {
                l1++,l2++;
            }
            if(a[i]==2&&a[n]==2) l2++;
        }
        cout<<l1<<" "<<l2;
        return 0;
    }
    for(int l=1;l<=n;l++)
    {
        cnt=0;
        memset(q,0,sizeof(q));
        memset(b,0,sizeof(b));
        for(int i=l;i<=n;i++)
        {
            if(b[a[i]])
            {
                int x=b[a[i]];
                for(int j=x;j<=cnt;j++)
                {
                    b[q[j]]=0;
                    q[j]=0;
                }
                cnt=x-1;
            }
            if(!b[a[i]])
            {
                cnt++;
                q[cnt]=a[i];
                b[a[i]]=cnt;
            }
        }
        for(int i=1;i<=cnt;i++)
        {
            ans[q[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;

}
