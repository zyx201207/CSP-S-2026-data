#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 100;

ll lenth = 0;
ll vis = 1;
ll ans = 0;
ll n;
string s;

char c[N];
ll r[N];

inline ll read() 
{
	ll x = 0;
	ll f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') 
	{
		if (ch == '-') 
		{
			f = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') 
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int main() 
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n ;i ++ ) 
	{
		r[i] = read();
		cin >> c[i];
		lenth += r[i]; 
	}
	
	if (lenth < 1000000000)  
	{
		for (int i = 1; i <= n; i ++ ) 
		{
			for (int j = 0; j < r[i]; j ++ ) 
			{
				s += c[i];
			}
		}
		
		for (int i = 0; i < lenth / 2; i ++ ) 
		{
			if (s[i] != s[lenth - 1 - i]) 
			{
				ans ++;
				s[lenth + 1 - i] = s[i];
			}
		}
		
		cout << ans;
	}
	
	else 
	{
		cout << lenth / 2;
	}
}
