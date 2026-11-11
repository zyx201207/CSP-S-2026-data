#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e5+5;

// 题意: 将 ai 个 ci 拼在一起, 求 s 要改多少个字符能变成回文串 

int n;
ll cnt = 0, x;
char c; 
vector<pair<ll,char> > a;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++) 
	{
		cin>>x>>c;
		if(i > 0 && c == a[i-1].second)
		{
			// 合并 
			a[i-1].first += x;
		}
		else a.push_back({x,c});
	}
	
	int i = 0, j = a.size()-1;
	while(i <= j)
	{
		if(i == j) break; // 就剩一种字母了, 肯定是回文串 
		ll l = a[i].first, r = a[j].first;
		char lc = a[i].second, rc = a[j].second;
		if(lc != rc) cnt += min(l,r); 
		if(l == r) i++, j--;
		if(l < r) i++, a[j].first -= l;
		if(l > r) j--, a[i].first -= r;
	}
	cout<<cnt;
	
	return 0;
} 
