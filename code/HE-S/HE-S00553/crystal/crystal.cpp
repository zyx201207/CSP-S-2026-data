#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000005],js[10000005]; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>> n >> m;
	//输入a数组
	for(long long i = 1;i <= n;i ++)
	{
		cin>> a[i];
	}
	//升序排列a数组
	sort(a + 1,a + n + 1);
	long long maxs = 0;
	for(long long i = 1;i <= m;i ++)
	{
		//让a数组中最小的数加一
		a[1] ++;
		for(long long j = 1;j <= n;j ++)
		{
			js[a[j]] = 0; 
		}
		for(long long j = 1;j <= n;j ++)
		{
			js[a[j]] ++;
		}
		for(long long j = 1;j <= n;j ++)
		{
			if(js[a[j]] != 0)
			{
				maxs = max(maxs,js[a[j]]);
			}
		}
//		cout<< maxs << ' '; 
		//重新升序排列a数组
		sort(a + 1,a + n + 1);
	}
	cout<< maxs;
	//保存时，解注释 
	return 0;
}
