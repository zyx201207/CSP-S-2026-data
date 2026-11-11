#include<bits/stdc++.h>
using namespace std;
long long e[6060][6060],a[505050],t[505050],w[505050],ans;
int c,q,d,n,m,k,x,y;

void floyd()
{
	for(int l=1;l<=m;l++)
	 {
	 	for(int i=1;i<=m;i++)
	 	 {
	 	 	for(int j=1;j<=m;j++)
	 	 	 {
	 	 	 	if(e[i][j]>e[i][l]+e[l][j])
	 	 	 	 {
	 	 	 	 	e[i][j]=e[i][l]+e[l][j];
					}
			   }
		  }
	 }
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++)
	 {
	 	cin>>w[i];
	 	for(int j=1;j<=m;j++)
	 	 {
	 	 	e[i][j]=0x3f3f3f3f;
		  }
	 }
	for(int i=1;i<=n;i++)
	 {
	 	cin>>k;
	 	for(int j=1;j<=k;j++)
	 	 {
	 	 	cin>>a[j]>>t[a[j]];
	 	 	for(int l=1;l<j;l++)
	 	 	 {
	 	 	 	e[a[j]][a[l]]=min(e[a[j]][a[l]],t[a[l]]+t[a[j]]);
	 	 	 	e[a[l]][a[j]]=min(e[a[l]][a[j]],t[a[l]]+t[a[j]]);
			   }
		  }
	 }
	floyd();
	for(int i=1;i<=q;i++)
	 {
	 	cin>>x>>y;
	 	ans=e[x][y]+w[x]+w[y];
	 	cout<<ans<<"\n";
	 }
	return 0;
}
