#include <bits/stdc++.h>
using namespace std;
int c[10000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,m;
	long long num=0;
	cin>>a>>m;
	for(int i=1;i<=m;i++)
	{
		cin >>c[i];
	}
	for(int j=1;j<=100000;j++)
	{
		m=m-j;
		if(m<=0)
		{
			break;
		}
		num++;
	}
	cout<<num+1;
	return 0;
}
