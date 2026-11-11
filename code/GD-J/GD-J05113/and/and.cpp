#include<bits/stdc++.h>
using namespace std;
long long dp[300005];
long long num[300005];
long long a[300005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long sum=a[1];
	if(m==1)
	{
		cout<<sum;
		return 0;
	}
	if(m==2)
	{
		sum=a[1]&a[2];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				sum=a[i]&a[j];
				if(sum!=0)
				{
					cout<<sum;
					return 0;
				}
			}
		}
		cout<<sum;
		return 0;
	}	
	for(int f=2;f<=m;f++)
	{
		sum &= a[f];
	}
	cout<<sum;
}
