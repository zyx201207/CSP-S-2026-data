#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","R",stdin);
	freopen("and.out","W",stdout);
	int n,m;
	long long a[200001],b[200001][200001];
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int j=1;
		while(a[i])
		{
			b[i][j]=a[i]%2;
			a[i]/=2;
			j++;
		}
	}
	int max=0,num=0;
	for(int i=1;i<=n;i++)
	{
		num=0;
		for(int j=i;j<=n;j++)
		{
			int k=1;
			if(b[i][k]==b[j][k])num+=b[i][k]*2**k;
			k++;
		}
		if(max<num)max=num;
	}
	cout<<max;
	return 0;
}	
