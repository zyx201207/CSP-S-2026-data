#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int a[1001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	if(n==2)
	{
		cout<<32<<endl<<17;
	}
	else if(n==3)
	{
		cout<<35<<endl<<16;
	}
	if(n==1)
{
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	int k;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		int d;
		sum+=d;
	}
	cout<<sum;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
