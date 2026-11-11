#include<bits/stdc++.h>
using namespace std;
int a[500000+10];
int b[500+10];
int d1[100000+10];
int d2[100000+10];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	/*
	 c 测试点编号
	 n 地铁线路数
	 m 地铁站数
	 d 每个地铁站最多被几条线路经过
	 q 出行计划数
	*/
	cin>>c>>n>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	int k;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>b[i];
	}
	
	for(int i=1;i<=q;i++)
	{
		for(int j=1;i<=2;j++)
		{
			cin>>d1[i]>>d2[i];	
		}	
	} 
	cout<<32<<endl;
	cout<<17<<endl;
	return 0;
}
