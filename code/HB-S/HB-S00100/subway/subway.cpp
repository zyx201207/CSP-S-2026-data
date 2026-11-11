#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[100001]={0};
int k[100001]={0};
int a[100001][501]={0};
int t[100001][501]={0};
int x[100001]={0};
int y[100001]={0};
int dp[100001]={999};


int dg(d,g)
{
   for(int j=0;j<k[d];j++)
      {
          dp[a[d][j]]=min(dp[x[d]]+2*t[d]),dp[a[d][j]]);
          if(d!=g)
          {
            dg(k[j],g);
          }
      }
    return 0;

}



int main()
{
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
   for (int i = 0; i < m; i++)
   {
      cin>>w[i];
   }
    for (int i = 0; i < n; i++)
   {
      cin>>k[i];
      for (int j = 0; j < k[i]; j++)
      {
         cin>>a[i][j];
         cin>>t[i][j];
      }

   }
  for (int i = 0; i < q; i++)
  {
     cin>>x[i];
     cin>>y[i];
  }
    for (int i = 0; i < q; i++)
  {
      dp[100001]={999};
      dp[x[i]]=w[i]+t[i];
      dg(x[i],y[i]);
      cout<<dp[y[i]]-t[y[i]]+w[i]<<endl;

  }
  return 0;
}
