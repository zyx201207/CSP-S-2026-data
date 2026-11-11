//GZ-J00090 ∫Œ”Í–˘
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i = 1;i <= n;i++)
	{
		for(long long j = 1;j <= n;j++)
		{
			if(a[j]<a[j+1])
			{
				long long t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	long long num = a[1];
	for(int i = 2;i <= m;i++)
	{
		num=num&a[i];
	}
	cout <<num;
	return 0;
} 
