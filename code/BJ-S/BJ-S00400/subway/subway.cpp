#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
   int to,l;
};
vector<node> li[510],ex[500010];
int c,n,m,d,q;
int a[500010],vis[500010];
void bfs(int x,int y)
{
   queue<int>q;
   q.push(x);
   vis[x]=0;
   while(!q.empty())
   {
      int t=q.front();
      q.pop();
      if(t==y) return;
      for(auto i:li[t])
      {
         vis[i.to]=min(vis[i.to],vis[t]+i.l);
         q.push(i.to);
      }
   }
}
signed main()
{
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
   cin>>c>>n>>m>>d>>q;
   for(int i=1;i<=m;i++)
   {
      cin>>a[i];
   }
   for(int i=1;i<=n;i++)
   {
      int x;
      cin>>x;
      for(int j=1;j<=x;j++)
      {
         int st,l;
         cin>>st>>l;
         if(!ex[st].empty())
         {
            for(auto k:ex[st])
            {
               li[i].push_back({k.to,l+k.l-a[st]});
               li[k.to].push_back({i,l+k.l-a[st]});
            }
         }
         ex[st].push_back({i,l+a[st]});
      }
   }
   while(q--)
   {
      int l,r,ans=1e9;
      cin>>l>>r;
      for(auto i:ex[l])
      {
         for(auto j:ex[r])
         {
            memset(vis,0x3f,sizeof vis);
            bfs(i.to,j.to);
            ans=min(ans,vis[j.to]+i.l+j.l);
         }
      }
      cout<<ans<<endl;
   }
   return 0;
}
