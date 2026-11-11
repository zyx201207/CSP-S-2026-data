#include <bits/stdc++.h>
using namespace std;
const int N=310;
int c,t;
int n,d;
int x[N],f[N][N];
int tot[N][N][N];
int main()
{
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  cin>>c>>t;
  while(t--)
  {
	memset(f,0x3f3f3f,sizeof f);
	memset(tot,0,sizeof tot);
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++) scanf("%d",x+i);
	for(int i=1;i<=n;i++) f[i][i]=1;
	
	for(int l=1;l<=n;l++)
	 for(int r=l+1;r<=n;r++)
	 {
	  for(int i=l;i<=r;i++)
	   for(int j=l;j<=i;j++)
	   if(x[i]-x[j]<=d)
	   {
		   f[l][i]=min(f[l][i],f[l][j]+1);
		   if(r==i and f[l][j]+1<N) tot[l][i][f[l][j]+1]++;
	   }
	 }
	 
	int ans=0;
	for(int i=1;i<=n;i++)
	 for(int j=i+1;j<=n;j++)
	 if(f[i][j]<N)
	 if(tot[i][j][f[i][j]]==2) ans++;
	printf("%d\n",ans);
  }
  return 0;
}
