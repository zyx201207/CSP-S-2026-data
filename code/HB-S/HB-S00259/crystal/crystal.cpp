#include <bits/stdc++.h>
using namespace std;
int a[5005];
struct cc
{
	int t;//cha
	int xh;
}c[5005][5005]={};
bool cmp(cc x,cc y)
{
	return x.t<y.t;
}//cha:xiao-da(fuzaiqian
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m,maxn=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		//cout<<i<<":"<<endl;
		
		for(int j=0;j<n;j++)
		{
			c[i][j].t=a[i]-a[j];
			c[i][j].xh=j;//yuanlaixuhao
			//px correct
			//cout<<i<<" "<<j<<" "<<c[i][j]<<"px"<<endl;
		}
		//c[i][i]=2147483647;
		sort(c[i],c[i]+n,cmp);
		
		/*
		for(int j=0;j<n;j++)
		{
			cout<<c[i][j].t<<" "<<endl;
		}
		cout<<endl;
		*/
		int sum=0,cn=0,cnt=1;
		while(sum<=m&&cn<n)//meichao m ci
		{
			if(c[i][cn].t+sum<=m && c[i][cn].xh!=i && c[i][cn].t>=0)
			{
				sum+=c[i][cn].t;//caozuo
				cnt++;
				//cout<<c[i][cn].t<<" "<<sum<<" "<<cnt<<endl;
				
			}
			if(sum==m)break;
			cn++;
		}
		if(cnt>maxn)//shuijingduo
		{
			maxn=cnt;
		}
		//cout<<maxn<<endl;
	}
	cout<<maxn;
	return 0;
}
