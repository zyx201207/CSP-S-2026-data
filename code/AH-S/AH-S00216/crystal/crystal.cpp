#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],c[500010];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int sum=0;
    bool pd=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        if(a[i]-a[i-1]!=a[i-1]-a[i-2]&&i!=1) pd=0;
    }
    if(pd==1||n>=3e8)
    {
        int p=(n+1)/2;
        for(int i=1;i<=p;i++)
        {
            c[i]=abs(a[i]-a[p]);
        }
        sort(c+1,c+n+1);
        int ans=1;
        for(int i=1;i<=p;i++)
        {
            if(m>=c[i])
            {
                if(i!=p)
                {
                    ans++;
                    m-=c[i];
                }
            }
            else
            {
                break;
            }
        }
        cout<<ans;
    }
    else
    {
        int maxn=0;
        for(int p=1;p<=n;p++)
        {
            for(int i=1;i<=p;i++) c[i]=abs(a[i]-a[p]);
            sort(c+1,c+n+1);
            int ans=1;
            for(int i=1;i<=p;i++)
            {
                if(m>=c[i])
                {
                    if(i!=p)
                    {
                        ans++;
                        m-=c[i];
                    }
                }
                else
                {
                    break;
                }
            }
            maxn=max(maxn,ans);
        }
        cout<<maxn;
    }
}
