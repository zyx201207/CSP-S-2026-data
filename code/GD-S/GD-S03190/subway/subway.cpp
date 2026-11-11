#include<bits/stdc++.h>
using namespace std;
long long x,y,n,m,s[2004][2004],t[2004][2004],a[2004][2001],w[2001],k[501000],i,j=1,l,o,c,d,p,q;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>p;
	for(i=1;i<=2000;i++)for(j=1;j<=2000;j++)s[i][j]=999999999;
	for(i=1;i<=n;i++)cin>>w[i];
	for(i=1;i<=m;i++)
	{
		cin>>k[i];
		for(j=1;j<=k[i];j++)
		{
			cin>>a[i][j];cin>>t[i][j];
		}
		for(j=1;j<=k[i];j++)
		{
		for(l=1;l<=k[i];l++)if(l!=j){
			if(s[a[i][j]][a[i][l]]>t[i][j]+t[i][l])
			s[a[i][j]][a[i][l]]=t[i][j]+t[i][l];
		}
		}
	}
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	for(l=1;l<=n;l++)
	{
		if(i==j||i==l||j==l)continue;
		if(s[i][j]>s[i][l]+s[l][j])s[i][j]=s[i][l]+s[l][j];
		
	}
	while(p>0){
	cin>>x>>y;
	cout<<s[x][y]+w[x]+w[y]<<"\n";p--;
}
	return 0;
}
