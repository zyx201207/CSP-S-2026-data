#include <bits/stdc++.h>
#define N 5005
#define int long long
#define inf 0x3f3f3f3f
using namespace std;
int n,m,a[N],f[N],ans;
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;cin>>C>>T;
    while(T--)
    {
        cin>>n>>m;ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=2;i<=n;i++)
        {
            int p=upper_bound(a+1,a+i+1,a[i]-m)-a-1;
            if(!p)p=1;
            //cout<<p<<"\n";
            int minn=inf,cnt=0,maxn=-inf;
            for(int j=p;j<i;j++)
                minn=min(minn,f[j]),maxn=max(maxn,f[j]);
            //cout<<"minn:"<<minn<<"\n\n\n\n\n";
            for(int j=p;j<i;j++)cnt+=(f[j]==minn);
            f[i]=max(maxn,f[p]+1),ans+=(f[i]==2);
        }cout<<ans<<endl;
        //for(int i=1;i<=n;i++)cout<<f[i]<<" ";
    }
    return 0;
}
