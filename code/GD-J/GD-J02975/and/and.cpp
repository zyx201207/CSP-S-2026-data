#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const long long N = 2e5+10;
vector<int> nums;
long long n,m,ans;
void js(long long cs)
{
	for(long long i = cs;i>=0;i--)
	{
		vector<int> ls;
		for(long long j=0;j<nums.size();j++)
		{
			if(nums[j]&(1<<i))
			{
				ls.push_back(nums[j]);
			}
		}
		if(ls.size()>=m)
		{
			nums = ls;
			js(i-1);
			return;
		}
	}
	ans = nums[0];
	for(long long i=0;i<nums.size();i++)
	{
		ans &= nums[i];
		//printf("nn%lld  ",nums[i]);
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i=0;i<n;i++)
	{
		long long a;
		scanf("%lld",&a);
		nums.push_back(a);
	}
	js(30);
	printf("%lld",ans);
	return 0;
}
