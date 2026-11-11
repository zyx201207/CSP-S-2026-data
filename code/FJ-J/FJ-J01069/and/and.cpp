#include<bits/stdc++.h>
using namespace std;
long long n,m,nm;
long long a[200010][32],b[200010],c[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>b[i];
		long long j=0;
		while(b[i]!=0)
		{
			j++;
			a[i][j]=b[i]%2;
			b[i]/=2;
		}
	}
	for(long long i=31;i>=1;i--)
	{
		long long s=0;
		for(long long j=1;j<=n;j++)
		{
			if(a[j][i]==1&&c[j]!=1)
			{
				s++;
			}
		}
		if(s>=m)
		{
			nm+=pow(2,i-1);
			for(long long j=1;j<=n;j++)
			{
				if(a[j][i]!=1)
				{
					c[j]=1;
				}
			}
		}
	}
	cout<<nm;
	return 0;
}
