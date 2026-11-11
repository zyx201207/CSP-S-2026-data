#include<bits/stdc++.h>
using namespace std;
int a[100000005];

int main()
{
	
	preopen("crystal.in","r",stdin);
	preopen("crystal.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	long long sum=1;
	for(int i=1;i<= n;i++)
	{
		cin >> a[i];
	}for(int i=2;i<=n;i++)
	{
		long long b=0;
		for(int j=1;j<i;j++)
		{
			 b+=a[i]-a[j];
		}
		if(m>=b)
		{
			sum++;
		}
	}
	cout << sum;
	
	return 0;
}
