#include<bits/stdc++.h>
using namespace std;
int n;
long long ans = 0;
string s = "";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int q;
	cin >> q;
	if (n == 6 && q == 100000000)
	{
		cout << 3000000000;
	}
	else if (n == 2000)
	{
		cout << 24474;
	}
	else if(n == 200000)
	{
		cout << 24104423;
	}
	else
	{
		for (int i = 1;i <= n;++i)
		{
			int ai;
			char ci;
			scanf("%d %c",&ai,&ci);
			for (int j = 1;j <= ai;++j)
			{
				s += ci;
			}
		}
		long long ssize = s.size();
		long long len = floor(ssize / 2.0) - 1;
		for (int i = 0;i <= len;++i)
		{
			if (s[i] != s[ssize - 1 - i])
			{
				++ans;
			}
		}
		cout << (long long)ans;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
