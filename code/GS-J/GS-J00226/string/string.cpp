#include <bits/stdc++.h>

using namespace std;
long long a;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    long long td = 0, ans = 0;
    string s = "";
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a;
        char s1;
        cin >> s1;
        for(int j = 0;j < a;j++)
        {
        	s[td++] = s1;
		}
        a = 0;
    }
    string st;
    long long nt = s.size() / 2;
    if(s.size() % 2 != 0)
    {
        for(int i = 1;i <= n;i++)
        {
            st[i] = s[i + nt + 1];
        }
    }
    else
    {
    	for(int i = 1;i <= n;i++)
        {
            st[i] = s[i + nt];
        }
	}
	for(int i = 0;i < s.size();i++)
	{
		if(st[i] != s[i])
		{
			ans++;
		}
	}
	cout << ans;
    return 0;
}

