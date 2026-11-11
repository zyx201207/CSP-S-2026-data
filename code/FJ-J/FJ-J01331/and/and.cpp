#include<bits/stdc++.h>
using namespace std;
//好熟悉的题目...我之前疑似遇到过？
//考虑每一位能否取到 1 ，然后扫一遍 check 就做完了 
//感觉 T3 << T1 << T2 至少在实现上 

const int N = 200005;

int n, m, a[N], ans = 0;

bool ch(int x)
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if((x & a[i]) == x)cnt++;
	}
	if(cnt >= m)return 1;
	return 0;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout); 
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	
	for(int i = 30; i >= 0; i--)
	{
		int x = ans + (1 << i);
		if(ch(x))ans = x;
	}
	
	cout << ans;
	
	return 0;
}  
