#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	vector<long long> a(n+1);
	a[0] = 0;
	for(int i = 1;i <= n;++i)
		cin>>a[i];
	sort(a.begin()+1,a.end());
	for(int i = 1;i <= n;++i)
		a[i] += a[i-1];
	long long ans = 1;
	for(long long i = 1;i <= n;++i)
	{
		for(long long j = n;j > i;--j)
		{
			if(j - i + 1 <= ans)break;
			__int128 sum = (a[j]-a[j-1])*
			(j-i)-a[j-1]+a[i-1];
			if(sum <= m && sum >= 0)
			{
				ans = max(ans,j-i+1);
				break;
			}
		}
	}
	cout<<ans;
}
