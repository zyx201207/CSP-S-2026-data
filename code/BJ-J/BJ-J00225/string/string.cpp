#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , char> plc;

map<ll , int> mp;
ll n , L , len , res;
char c;
vector<plc> tot , s1 , s2 , s3;
struct node
{
	ll xl , xr;
	char ch;
};
vector<node> n1 , n2 , f1 , f2;
vector<ll> has;

int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	//in
	cin >> n;
	for(int i = 0 ; i < n ; ++ i)
	{
		cin >> len;
		L += len;
		cin >> c;
		tot.emplace_back(len , c);
	}
	
	//divid
	ll l = 1 , r = 0 , now = 0 , mid = (L + 1) / 2;
	for(auto x : tot)
	{
		now += x.first;
		r = now;
		if((L % 2 && r < mid) || (L % 2 == 0 && r <= mid)) s1.emplace_back(x.first , x.second);
		else if((L % 2 && l > mid) || (L % 2 == 0 && l >= mid)) s2.emplace_back(x.first , x.second);
		else
		{
			ll left = mid - l + 1 , right = r - mid + 1;
			s1.emplace_back(left , x.second) , s2.emplace_back(right , x.second);
		}
		l = r + 1;
	}
	
	//reverse
	for(int i = s2.size() - 1 ; i >= 0 ; -- i)
	{
		auto x = s2[i];
		s3.emplace_back(x.first , x.second);
	}
	
	//break down
	now = 0 , l = 1 , r = 0;
	for(auto x : s1)
	{
		now += x.first;
		r = now;
		n1.push_back({l , r , x.second});
		mp[l] = 1 , mp[r] = 1;
		l = r + 1;
	}
	now = 0 , l = 1 , r = 0;
	for(auto x : s3)
	{
		now += x.first;
		r = now;
		n2.push_back({l , r , x.second});
		mp[l] = 1 , mp[r] = 1;
		l = r + 1;
	}
	
	for(auto x : mp) has.push_back(x.first);
	int sz = has.size();
	
	int idx = 0;
	for(auto x : n1)
	{
		ll lst = x.xl;
		while(has[idx] <= x.xr && idx < sz)
		{
			f1.push_back({lst , has[idx] , x.ch});
			lst = has[idx] + 1;
			++ idx;
		}
	}
	idx = 0;
	for(auto x : n2)
	{
		ll lst = x.xl;
		while(has[idx] <= x.xr && idx < sz)
		{
			f2.push_back({lst , has[idx] , x.ch});
			lst = has[idx] + 1;
			++ idx;
		}
	}
	for(int i = 0 ; i < f1.size() ; ++ i)
	{
		res += (f1[i].ch != f2[i].ch) * (f1[i].xr - f1[i].xl + 1);
	}
	
	cout << res << '\n';
	
	return 0;
}
