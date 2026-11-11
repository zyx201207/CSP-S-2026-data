#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
long long ans;
int n;
string S2;
struct S1
{
	long long a;
	char c;
}s[MAXN];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> s[i].a >> s[i].c; 
		for (int j = 1;j <= s[i].a;j++)
		{
			S2 += s[i].c;
		}
	}
	for (int i = 0,j = S2.size() - 1;i < S2.size() / 2;i++,j--)
	{
		if(S2[i] != S2[j])
		{
			ans++;
		}
	}
	cout << ans << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
