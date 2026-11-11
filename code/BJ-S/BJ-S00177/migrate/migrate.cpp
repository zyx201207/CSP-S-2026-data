#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[15],s[15][15][15];
int n,m;
void dfs(int rt,int cur,int st)
{
    s[rt][cur][st]++;
    if(cur==n)
    {
        return ;
    }
    for(int i=cur+1;i<=n;i++)
    {
        if(a[i]-a[cur]<=m)
            dfs(rt,i,st+1);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int T,c;
    cin>>T>>c;
    while(T--)
    {
        cin>>n>>m;
        memset(s,0,sizeof(s));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            dfs(i,i,0);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=0;k<=n;k++)
                {
                    if(s[i][j][k]!=0)
                    {
                        if(s[i][j][k]==2)
                            ans++;
                        break;
                    }
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
