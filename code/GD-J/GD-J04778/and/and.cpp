#include<bits/stdc++.h>
using namespace std;

int lowbit(int x)
{
	return x & (-x);
}

int abd(int x)
{
	int ans = 0;
	while(x != 0)
	{
		x -= lowbit(x);
		ans++;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	vector<pair<int,int>>a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i].second;
		a[i].first = abd(a[i].second);
	}
	sort(a.begin(), a.end(), [](const pair<int,int> & x, pair<int,int> & y)
	{
		if(x.first != y.first) return x.first > y.first;
		return x.second > y.second;
	});
	int ans = a[0].second;
	for(int i=1;i<m;i++) ans = (ans & a[i].second);
	cout<<ans;
	return 0;
}

/*
5
3
7
15
12
1
0

*/
