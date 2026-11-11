#include <bits/stdc++.h>
using namespace std;
int n, cnt, ans;
string s;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    while(n--)
    {
        int a;
        cin >> a;
        cnt += a;
        cin >> s;
    }
    int i = 1, j = cnt;
    while(i <= j)
    {
		if(s[i] != s[j])
			ans++;
		i++;
		j--;
	}
    cout << ans;
    return 0;
}