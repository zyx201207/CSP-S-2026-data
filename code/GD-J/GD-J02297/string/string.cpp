#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;

long long n;
long long cnt[MAXN];
char c[MAXN];
long long presum[MAXN];
vector<char>stk;
long long ret = 0;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i = 1;i <= n;i++)
	{
		cin >> cnt[i] >> c[i];
		presum[i] = presum[i-1] + cnt[i];
	}
	for(long long i = 1;i <= presum[n] / 2;i++)
	{
		int l = lower_bound(presum+1,presum+n+1,i) - presum;
		stk.push_back(c[l]);
	}
	for(long long i = (presum[n] / 2 + 1 + (presum[n] % 2 == 1));i <= presum[n];i++)
	{
		long long l = lower_bound(presum+1,presum+n+1,i) - presum;
		if(c[l] != stk.back()) ret++;
		stk.pop_back();
	}
	cout << ret <<'\n';
	return 0;
}
