#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,d,cnt,minn,a[N];
void dfs(int x,int y,int deep)
{
    if(x==y)
    {
        if(minn>deep)
        {
            minn=deep;
            cnt=1;
        }
        else if(minn==deep)
            cnt++;
        return ;
    }
    for(int i=x+1;i<=y;i++)
    {
        if(a[i]-a[x]<=d)
            dfs(i,y,deep+1);
        else
            break;
    }
    return ;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
            {
                cnt=0,minn=1e18;
                dfs(i,j,0);
                if(cnt==2)
                    ans++;
            }
        cout<<ans<<'\n';
    }
    return 0;
}
