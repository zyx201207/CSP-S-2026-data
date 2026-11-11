#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n ; 
	cin >> n;
	int a ;
	char c;
	string s;
	int ans = 0;
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> a >> c;
	}
	s += a * c;
	int l = s.size();
	for(int i = 0 ; i < s.size() ; i ++)
	{
		if(s[i] == s[l + 1 - i])
		{
			ans = 0;
		}
	}
	cout << ans;
	return 0;
}
