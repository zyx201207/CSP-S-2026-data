#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	
	cin>>n;
	ll sum = 0;
	vector<pair<int, int> > a(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first;
		sum += a[i].first;
		char c;
		cin>>c;
		a[i].second = (c - 'a');
	}
	
	ll l = 1, r = n, ans = 0;
	while(l < r)
	{
		int & x = a[l].first;
		int & y = a[r].first;
		int k = min(x, y);
//		cout<<k<<"\n";
		if(a[l].second == a[r].second)
		{
			x-=k, y-=k;
		}
		else 
		{
			ans += k;
			x-=k, y-=k;
		}
		if(x==0) l++;
		if(y==0) r--;
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

