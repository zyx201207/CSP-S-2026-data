#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long

using namespace std;
int c,n,m,d,Q;
int w[20005],h[501],s[501][1005],t[501][1005];
ll a[1005][1005],vis[1005][1005];
queue<int> q;
void spfa(int t)
{
   q.push(t);
   ll dp[1005];
   memset(dp,0x3f3f3f,sizeof(dp));
   dp[t]=0;
   while(!q.empty())
   {
     int nw=q.front();
     q.pop();
     for(int i=1;i<=m;i++)
     {
       if(nw==i) continue;
       if(dp[nw]+a[nw][i]<dp[i])
       {
         dp[i]=dp[nw]+a[nw][i];
         q.push(i);
       }
     }
   }
   for(int i=1;i<=m;i++)
   {
     if(i==t) continue;
     vis[t][i]=w[t]+dp[i]+w[i];
   }
}
int main()
{
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
   scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
   for(int i=1;i<=m;i++)
     scanf("%d",&w[i]);
   memset(a,0x3f3f3f,sizeof(a));
   for(int i=1;i<=n;i++)
   {
     scanf("%d",&h[i]);
     for(int j=1;j<=h[i];j++)
       scanf("%d%d",&s[i][j],&t[i][j]);
     for(int j=1;j<=h[i];j++)
       for(int k=j+1;k<=h[i];k++)
       {
         ll tmp=t[i][j]+t[i][k];
         a[s[i][j]][s[i][k]]=min(tmp,a[s[i][j]][s[i][k]]);
         a[s[i][k]][s[i][j]]=min(tmp,a[s[i][k]][s[i][j]]);
       }
   }
   for(int i=1;i<=m;i++)
     spfa(i);
   for(int i=1;i<=Q;i++)
   {
     int x,y;
     scanf("%d%d",&x,&y);
     cout<<vis[x][y]<<endl;
   }
   return 0;
}

