#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[1000010];
long long timet[10010][10010];
long long dis[10010][10010];
long long a,k,t;
long long begin,end;
int main()
{
 freopen("subway.in","r",stdin);
 freopen("subway.out","w",stdout);
 cin>>c>>n>>m>>d>>q;
 for(int i=1;i<=m;i++)
 {
  cin>>w[i];
 }
 for(int i=1;i<=n;i++)
 {
  cin>>k;
  for(int j=1;j<=k;j++)
  {
   cin>>a>>t;
   timet[i][a]=t;
  }
 }
 for(int i=1;i<=q;i++)
 {
  cin>>begin>>end;  
  
 }
 return 0;
}
