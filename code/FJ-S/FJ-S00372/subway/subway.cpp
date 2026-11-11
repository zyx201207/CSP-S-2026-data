#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,u[100005],v[100005],ans=0;
int w[100005],a[501][500005]={0},t[501][100005];
int find(int x)
{
	for(int i=1;i<=n;i++)
  {
  	for(int j=1;j<=m;j++)
  	{
  		if(a[i][j]==x)
  		{
  		return i;	
		}
	}
  }
}
int cross(int x,int y)
{
	for(int i=1;i<=m;i++)
  	{
  		for(int j=1;j<=m;j++)
  		{
  		  if(a[x][i]==a[y][j])
		  {
		  return a[x][i];
		  }	
		}
	}
	return -1;
}
void solve(int qq)
{
  ans+=w[u[qq]]+w[v[qq]];
  int here,go;
  here=find(u[qq]);
  go=find(v[qq]);
  ans+=t[go][cross(go,here)];
  ans+=t[here][cross(go,here)];
  cout<<ans<<endl; 
}
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
  	int p,cnt=1;
  	cin>>p;
	for(int j=1;j<=p;j++)
  	{
  		cin>>a[i][cnt]>>t[i][cnt];
  		cnt++;
  	}
  }
  for(int i=1;i<=q;i++)
  {
  	cin>>u[i]>>v[i];
  }
  for(int i=1;i<=q;i++)
  {
  	solve(i);
  }
}
