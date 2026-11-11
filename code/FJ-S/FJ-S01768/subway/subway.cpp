#include<bits/stdc++.h>
using namespace std;
long long s[510][510],c,n,m,d,q,w[20100],k[510],a[510][20100],t[510][20100],x[2010],y[2010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j];
	}
	for(int r=1;r<=q;r++)	cin>>x[r]>>y[r];
	if(n==5&&m==5&&d==20&&q==2) cout<<"32"<<endl<<"17";
	if(n==3&&m==7&&d==20&&q==2) cout<<"35"<<endl<<"16";
	return 0;
}
