#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	vector<vector<int>>a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i][i];
		for(int j=0;j<i;j++) a[i][j]=(a[i][i] and a[j][j]);
	}
	m--;
	long long sum=0;
	while(m--)
	{
		int max=-1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++) 
			{
				if(a[i][j]>max)
				{
					max=a[i][j];
					if (sum==0) sum=max;
					sum=sum and max;
					a[i][j]=-1;
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
} 
