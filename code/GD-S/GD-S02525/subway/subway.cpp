#include<bits/stdc++.h>
using namespace std;
long long arr[100005];
long long num[505][25];
long long sum[505][25];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long C,n,m,d,p=0;
	cin>>C>>n>>m>>d>>p;
	for(int i=1;i<=m;++i)
	{
		cin>>arr[i];
	}
	int a=0;
	for(int i=0;i<n;++i)
	{
		cin>>a;
		int j=0;
		while(cin)
		{
			cin>>num[i][j];
			cin>>sum[i][j];
			j++;
		}
	}
	long long x,y=0;
	int numx=0;
	for(int o=0;o<p;++o)
	{
		cin>>x>>y;
		numx+=arr[x];
		numx+=arr[y];
		for(int i=0;i<n;++i)
		{
			int j=0;
			while(num[i][j]==0)
			{
				if(num[i][j]==y)
				{
					numx+=sum[i][j];
				}
				j++;
			}
		}
	}
	
	return 0;
}
