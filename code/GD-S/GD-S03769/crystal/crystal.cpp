#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 5e5+5;

// 题意: 对长度为 n 的数组做 m 次操作, 每次给 1 个数 +1, 问最后最多有多少个数相同 

int n, ans = 1;
ll m;
ll a[maxn], sum[maxn];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i] = sum[i-1] + a[i];
	
	for(int i=2;i<=n;i++)
	{
		ll x = a[i];
		ll re = x*(i-1)-sum[i-1];
		if(re > m) break;
		else ans++;
	} 
	cout<<ans;
	
	return 0;
} 
