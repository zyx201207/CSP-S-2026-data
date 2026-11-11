#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

string s1 , s2;
int n;
LL ans;

int main()
{
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	
	cin >> n;
	for(int i = 1; i<=n; i++)
	{
		int x; char c;
		cin >> x >> c;
		while(x--)
			s1 += c;
	}
	int tmp = s1.size() / 2 + 1;
	s2 = s1.substr(tmp , s1.size() - tmp);
	reverse(s2.begin() , s2.end());
	s1.erase(tmp - 1);
	if(s1 == s2)
	{
		cout << 0;
		return 0;
	}
	for(int i = 0; i < s1.size(); i++)
	{
		if(s1[i] != s2[i])
			ans++;
	}
	cout << ans;
	
	return 0;
}
