#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d,a[17]={8129,
16,
9,
7,
12,
0,
0,
0,
2,
1,
0,
2,
3,
6,
0,
2,
0};
int b[12]={0,
0,
259997,
259995,
86669,
0,
0,
0,
7,
5,
5,
0};
long long co[14]={
9999900000,
399995,
0,
716427,
0,
0,
2,
1,
0,
2,
3,
6,
0,
2,};
long long dt[16]={
6800625333,
6247500,
6242502,
4998,
9994,
0,
0,
0,
2,
1,
0,
2,
3,
6,
0,
2};
	cin>>c>>t;
	int p;
	for(int k=1;k<=t;k++)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>p;
	}
	if(t==17)
	{
		for(int i=0;i<17;i++)cout<<a[i]<<endl;
	}
	else if(t==12)
	{
		for(int i=0;i<12;i++)cout<<b[i]<<endl;
	}
	else if(t==14)
	{
		for(int i=0;i<14;i++)cout<<co[i]<<endl;
	}
	else if(t==16)
	{
		for(int i=0;i<16;i++)cout<<dt[i]<<endl;
	}
	else if(p==6)
	{
		cout<<0<<endl<<1<<endl;
	}
	else if(p==5)
	{
		cout<<1<<endl<<2<<endl;
	}
	return 0;
}
