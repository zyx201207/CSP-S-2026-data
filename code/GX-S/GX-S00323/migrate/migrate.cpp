#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,d;
ll x[5001];
vector<int>e[5001];
ll ls[5010][5010],lc[5010][5010],ans;
void dfs(int s,int x,int fa)
{
    for(int y:e[x])
    {
        if(y!=fa)
        {
          if(lc[s][y]>lc[s][x]+1)
          {
              lc[s][y]=lc[s][x]+1;
              ls[s][y]=1;
          }
          else if(lc[s][y]==lc[s][x]+1)
          {
              ls[s][y]++;
          }
          else continue;
            dfs(s,y,x);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen ("migrate.in","r",stdin);
    freopen ("migrate.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--)
    {
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(x[j]-x[i]<=d)
                {
                    e[i].push_back(j);
                }
            }
        }
        memset(lc,0X3f3f3f3f,sizeof(lc));
        for(int i=1;i<n;i++){
           lc[i][i]=0;
            dfs(i,i,i);
            for(int j=i+1;j<=n;j++)
            {
                if(ls[i][j]==2)ans++;
            }
        }
        cout<<ans<<"\n";
        for(int i=1;i<=n;i++)
        {
            while(!e[i].empty())e[i].pop_back();
        }
        memset(ls,0,sizeof(ls));
    }
    return 0;
}
