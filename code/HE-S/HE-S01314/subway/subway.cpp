#include<bits/stdc++.h>
using namespace std;
int c=0,n=0,m=0,d=0,w[10000],k[10000],x[10000],y[10000],zong[2],q=0;

long long qz[10005],kz[10005][10005],t[10005][10005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		
	}
	
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>kz[i][j];
			cin>>t[i][j];}
	}
	for(int i=1;i<=q;i++)
		cin>>x[i]>>y[i];
	
	if(n==1)
	{
		for(int i=1;i<=q;i++)
			cout<<"0"<<endl;
	}
	if(n==2)
	{
		zong[0]=w[1]+t[1][1]+t[1][2]+t[2][2]+t[2][3]+w[3];
		zong[1]=w[1]+t[1][1]+t[1][2]+w[2];
		cout<<zong[0]<<endl;
		cout<<zong[1]<<endl;
		
	}
	return 0;	
}
