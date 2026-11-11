#include <bits/stdc++.h>

using namespace std;

long long n,a,cc_ans = 1,ans_i;
char ch;
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	while(n--)
	{
		cin >> a >> ch;
		while(a--)
		{
			s[cc_ans] = ch;
			cc_ans++;
		}
	}
	if(cc_ans % 2 == 0)
	{
		for(int i = 1; i <= cc_ans / 2; i++)
		{
			if(s[i] != s[cc_ans - i])
			{
				s[cc_ans - i] = s[i];
				ans_i++;
			}
		}
	}
	else
	{
		for(int i = 1; i <= (cc_ans - 1) / 2; i++)
		{
			if(s[i] != s[cc_ans - i])
			{
				s[cc_ans - i] = s[i];
				ans_i++;
			}
		}
	}
	cout << ans_i;
	return 0;
}
