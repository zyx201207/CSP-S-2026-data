#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> v[2000010];
int a[2000010],vis[2000010],len[2000010];
int cnt;
void bfs(int x,int y)
{
   queue<int>q;
   q.push(x);
   vis[x]=0;
   if(t==y) return;
   while(!q.empty())
   {
      int t=q.front();
      q.pop();
      for(auto i:v[t])
      {
         if(i==y)
         {
            len[++cnt]=vis[t]+1;
         }
         vis[i]=min(vis[i],vis[t]+1);
         q.push(i);
      }
   }
}
signed main()
{
   freopen("migrate.in","r",stdin);
   freopen("migrate.out","w",stdout);
   int c,t;
   cin>>c>>t;
   while(t--)
   {
      int n,d,ans=0;
      cin>>n>>d;
      for(int i=1;i<=n;i++)
      {
         cin>>a[i];
      }
      for(int i=1;i<=n;i++)
      {
         v[i].clear();
      }
      for(int i=1;i<=n;i++)
      {
         for(int j=i+1;j<=n;j++)
         {
            if(a[j]-a[i]<=d)
            {
               v[i].push_back(j);
            }
         }
      }
      for(int i=1;i<=n;i++)
      {
         for(int j=i+1;j<=n;j++)
         {
            memset(len,0,sizeof len);
            memset(vis,0x3f,sizeof vis);
            cnt=0;
            bfs(i,j);
            sort(len+1,len+cnt+1);
            if(len[1]==len[2]&&len[2]!=len[3]) ans++;
         }
      }
      cout<<ans<<endl;
   }
   return 0;
}
