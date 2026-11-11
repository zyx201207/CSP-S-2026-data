#include<bits/stdc++.h>
using namespace std;
long long a[20005];
long long n , m;
long long maxx = -1;
//long long two[35] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912};
long long dfs(long long m1 , long long p ,int dp)
{
	if(dp>=n)return 0;
	if(m1 == 0)return max(maxx , p);
	for(int i = dp; i <= n;i++)
	{
		dfs(m1-1 , (p&a[i]),i+1);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m ;
	for(long long i = 1; i <= n;i++)
	{
		cin >> a[i];
//		for(long long j = 21; j >= 0;j--)
//		{
//			if(a>=two[j])
//			{
//				b[i][j] = 1;
//				a-=two[j];
//			}
//		}
	}
//	for(int i = 1; i <= n;i++)
//	{
//		for(int j = 21; j >= 0;j--)cout << b[i][j];
//		cout << "\n";
//	}
	if(m == 2)
	{
		for(int i = 1; i <= n-1;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				maxx = max(maxx , dfs(m -2, (a[i]&a[j]) , i));
			}
		}
		cout << maxx;
		return 0;
	}
	if(m == 1)
	{
		for(int i = 1;i <= n;i++)
		{
			maxx = max(maxx , dfs(m -1, a[i] , i));
		}
		cout << maxx;
		return 0;
	}
	for(int i = 1; i <= n;i++)
	{
		maxx = max(maxx , dfs(m -1, a[i] , i));
	}
	cout << maxx;
	return 0;
}
