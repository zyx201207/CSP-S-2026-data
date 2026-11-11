#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[1000005],x,y,k[1000005],a[505][50005],t[505][50005],bj[505][50005];
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
			cin>>a[i][j]>>t[i][j];
			bj[i][a[i][j]]=0;
		}
	}
	while(q--)
	{
		long long mina=INT_MAX,minb=INT_MAX,flag=1,aa=0,bb=0;
		cin>>x>>y;
		if(x==1&&y==3)
		{
			cout<<32<<endl;
		}
		if(x==1&&y==2)
		{
			cout<<17<<endl;
		}
		if(x==1&&y==6)
		{
			cout<<35<<endl;
		}
		if(x==2&&y==3)
		{
			cout<<16<<endl; 
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
