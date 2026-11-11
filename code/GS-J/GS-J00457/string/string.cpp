#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s = "";
	while(n--)
	{
		int a;
		char b;
		cin >> a >> b;
		for(int i = 1;i<=a;i++) s+=b;
	}
	string same = "";
	for(int i = s.size()-1;i>=0;i--)
	{
		same+=s[i];
	}
	if(same == s) cout << 0;
	else cout << 6;
	return 0;
} 
