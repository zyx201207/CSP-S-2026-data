#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n, a[N], alllen, l, r, cnt;
char c[N];
deque<pair<long long, char>> dq;
int main()
{
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		alllen += a[i];
		cin >> a[i] >> c[i];
		if(a[i] == 0) continue; 
		dq.push_back({a[i], c[i]});
	}
	while(!dq.empty())
	{
		pair<long long, char> u1;
		pair<long long, char> u2;
		u1 = dq.front();
		u2 = dq.back();
		if(dq.size() == 1)
		{
			break;
		}
		if(u1.first > u2.first)
		{
			if(u1.second != u2.second)
			{
				cnt += u2.first;
			}
			dq.pop_front();
			dq.pop_back();
			dq.push_front({abs(u1.first - u2.first), u1.second});
		}else if(u1.first < u2.first)
		{
			if(u1.second != u2.second)
			{
				cnt += u1.first;
			}
			dq.pop_front();
			dq.pop_back();
			dq.push_back({abs(u2.first - u1.first), u2.second});
		}else if(u1.first == u2.first)
		{
			if(u1.second != u2.second)
			{
				cnt += u1.first;
			}
			dq.pop_front();
			dq.pop_back();
		}
	}
	cout << cnt;
	return 0;
}
