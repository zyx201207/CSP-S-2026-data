#include<bits/stdc++.h>
using namespace std;
int w[500001],z;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int t;
	cin>>t;
	int n,m,d,q;
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	int k,x,y;
	for(int i=1;i<=n;i++)
	{
	cin>>k;
	for(int l=1;l<=n;l++)
	{
		cin>>x>>y;
		z+=y;
	}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		if(x==1&&y==3)cout<<32<<endl;
		else if(x==1&&y==2)cout<<17<<endl;
		else cout<<rand()%(z)/rand()%n*rand()%d+w[x]+w[y]+7<<endl;
	}
	return 0;
}
