#include<bits/stdc++.h>
using namespace std;
long long n,a,flag[1000050],ans[1000050],maxn = -1e9,cut = 0;
bool mm = 0;
string b,c,f;
bool check()
{
	for(int i = c.size() - 1;i > 0;i--)
	{
		f[++cut] = c[i];
	}	
	for(int i = c.size() - 1;i > 0;i--)
	{
		if(f[i] != c[i])
		{
			mm = 1;
		}
	}	
	if(mm == 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool fff()
{
	if(maxn == 1) return true;
	else return false;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a >> b;
		for(int j = 1;j <= a;j++) 
		{
			c += b;
		}
	}
	if(check() == true)
	{
		cout << 0;
	}
	else
	{
		for(int i = 0;i < c.size();i++)
		{
			int cc = c[i] - '0';
			ans[cc]++;
		}
		for(int i = 1;i <= 74;i++)
		{
			maxn = max(ans[i],maxn);
		}
		if(fff() == true)
		{
			cout << c.size() - 2;
		}
		else
		{
			cout << maxn;
		}
	}
	return 0;	
} 
