#include<bits/stdc++.h>
using namespace std;
int a[50001][50001]={},m;
int ff(int xx,int yy,int kk){
	if(a[xx][yy]!=0)
	{
		return a[xx][yy];
	}
	int s=0,sum=0;
	for(int i=1;i<=m;i++)
	{
		if(a[xx][i]!=0&&i!=kk)
		{
			s=0;
			s=a[xx][i]+ff(i,yy,xx);
			if(s<sum||sum==0)
			{
				sum=s;
				break;
			}
		}
	}

	return sum;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	int c,n,d,q;
	cin>>c>>n>>m>>d>>q;

	int k[m+1]={};
	for(int i=1;i<=m;i++)
	{
		cin>>k[i];
	}
	int x=0,zhan1,t1,zhan2,t2;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		cin>>zhan1>>t1;
		for(int f=2;f<=x;f++)
		{
			cin>>zhan2>>t2;
			a[zhan1][zhan2]=t1+t2;
			a[zhan2][zhan1]=t1+t2;
			zhan1=zhan2;
			t1=t2;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int f=1;f<=m;f++)
		{
			if(a[i][f]==0&&i!=f)
			{
				a[i][f]=ff(i,f,0);
			}
		}
	}
	int qi,dao;
	for(int i=1;i<=q;i++)
	{
	cin>>qi>>dao;
	cout<<k[qi]+k[dao]+a[qi][dao]<<endl;	
	}
	return 0;
}
