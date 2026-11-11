#include<bits/stdc++.h>
using namespace std;
#define ll long long
int const N = 2e5 + 10;
ll n, m, a[N];
vector<ll> cnt[32];
vector<ll> ans;
void divi(ll x,int id)
{
	int k = 0;
	while(x)
	{
		if(x & 1)
			cnt[k].push_back(id);
		x >>= 1;
		k++;
	}
}
bool tfind(ll x)
{
	int l = 0, r = ans.size() - 1;
	while(l <= r)
	{
		int mid = (r + l) / 2;
		if(ans[mid] < x)
			r = mid - 1;
		else if(ans[mid] > x)
			l = mid + 1;
		else
			return 1;
	}
	return 0;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0;i < n;i++)
		cin >> a[i];
	sort(a, a + n);
	for(int i = n - 1;i >= 0;i--)
		divi(a[i], i), ans.push_back(i);
//	for(int i = 31;i >= 0;i--)
//	{
//		cout << " divide " << i << " " << cnt[i].size() << "\n";
//		for(int j = 0;j < cnt[i].size();j++)
//		{
//			cout << "  -> there are id " << cnt[i][j] ;
//			cout << " to " << a[cnt[i][j]]<< "\n"; 
//		}
//	}
	
	for(int i = 31;i >= 0;i--)
	{
		if(cnt[i].size() < m)
			continue;
		vector<ll> new_ans;
		for(int j = 0;j < cnt[i].size();j++)
		{
			if(tfind(cnt[i][j]))
				new_ans.push_back(cnt[i][j]);
		}
		if(new_ans.size() >= m)
			ans = new_ans;
//			cout << "at " << i << "ans size " << ans.size() << "\n"; 
	}
	int ans_out = a[ans[0]];
	for(int i = 1;i < min((ll)ans.size(), m);i++)
	{
		ans_out &= a[ans[i]];
	}
	cout << ans_out; 
	return 0;
 } 
