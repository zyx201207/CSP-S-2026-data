/*
17:00 shi tu xie n^2, shi bai le :(
17:11 n^3
17:13 n^3 cuo le
17:58 n^3 shi bai le, xing zhi xiang cuo le
18:06 bao sou 8pts
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,INF=3e18+10;
int c,t,n,d,a[N],mn[N][N],num[N][N];
void dfs(int x,int s,int cnt)
{
    //cout<<x<<"\n";
    if(cnt>mn[s][x])return;
    if(cnt<mn[s][x])
    {
        mn[s][x]=cnt;
        num[s][x]=1;
    }
    else if(cnt==mn[s][x])
    {
        ++num[s][x];
    }
    for(int i=x+1;i<=n;i++)
    {
        if(a[i]-a[x]>d)break;
        dfs(i,s,cnt+1);
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(mn,0x3f,sizeof(mn));
        memset(num,0,sizeof(num));
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;++i)
        {
            dfs(i,i,0);
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                if(num[i][j]==2)++ans;
            }
        }
        cout<<ans<<"\n";
    }
    //cout<<(double)clock()/CLOCKS_PER_SEC<<"\n";
    return 0;
}