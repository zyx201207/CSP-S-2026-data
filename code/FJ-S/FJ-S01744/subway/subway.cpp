#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N1 = 5e2 + 33;
const int N3 = 5e5 + 33;
int f[N1][N1],w[N3];
int c,c1,c2,d,n,m,q,kc,a,t;
int lk[N3][25],eg[N3][25],ans,cnt[N3];
void folyed()
{
	for(int i=1;i<=n;i++)
	  for(int g=1;g<=n;g++)
	    for(int l=1;l<=n;l++)
	      f[g][l]=min(f[g][l],f[g][i]+f[i][l]);
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++)
	{
	  cin>>kc;
	  f[i][i]=0;
	  for(int j=1;j<=kc;j++)
	  {
	  	cin>>a>>t;
	  	lk[a][++cnt[a]]=i;
	  	eg[a][cnt[a]]=t;
	  }
	}
	for(int i=1;i<=m;i++)
	{
	  for(int j=1;j<=cnt[i];j++)
	    for(int l=1;l<j;l++)
	    {
	      int x1=lk[i][j];
	      int x2=lk[i][l];
	      f[x1][x2]=min(f[x1][x2],eg[i][j]+eg[i][l]);
	      f[x2][x1]=f[x1][x2];
		}
	}
	folyed();
	for(int i=1;i<=q;i++)
	{
	  ans=1e16;
	  cin>>c1>>c2;
	  for(int j=1;j<=cnt[c1];j++)
	    for(int k=1;k<=cnt[c2];k++)
	      ans=min(ans,f[lk[c1][j]][lk[c2][k]]+eg[c1][j]+eg[c2][k]);//,cout<<ans<<" "<<j<<" "<<k<<"\n";
	  cout<<ans+w[c1]+w[c2]<<'\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/