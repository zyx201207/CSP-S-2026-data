#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls x<<1
#define rs x<<1|1
using namespace std;
const int N=5000+5;
ll c,t,n,d,a[N],mndis,tmp;
void dfs(int x,int y,int h)
{
    if(x==y)
    {
        if(h<mndis)mndis=h,tmp=0;
        tmp++;
    }
    for(int i=x+1;i<=y;i++)if(a[i]-a[x]<=d)dfs(i,y,h+1);
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12)
    {
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            int dis=a[2]-a[1];
            int p=d/dis;
            if(p<=1)
            {
                cout<<0<<'\n';
                continue;
            }
            if(n-p-1<0)cout<<0<<'\n';
            else cout<<n-2*p+1<<'\n';
        }
        return 0;
    }
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        int ans=0;
        for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)
        {
            mndis=2e9;
            dfs(i,j,0);
            if(tmp==2)ans++;
            tmp=0;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
