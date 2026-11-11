#include <bits/stdc++.h>
using namespace std;
char a[100000000];
char b[2];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n=0,num=0,m=0,mm=0,f=0,sum=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> m >> b[0];
		num+=m;
		for(int j=1;j<=m;j++)
		{
			a[mm]=b[0];
			mm++;
		}
	}
	f=num;
	if(num%2==1)
	{
		f=num+1;
	}
	for(int i=0;i<f/2;i++)
	{
		if(a[i]!=a[num-1-i])
		{
			sum++;
		}
	}
	cout << sum;
}
