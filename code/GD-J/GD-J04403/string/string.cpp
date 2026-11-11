#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
const int INF = 0x3f3f3f3f;

int n,ans;
string s;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int a;
		char c;
		cin >> a >> c;
		while(a--) 
			s += c;
	}
	
	int len = s.size();
	string s1,s2;
	s1 = s.substr(0,len/2);
	s2 = s.substr(len/2+1,len/2);
	reverse(s2.begin() , s2.end());
	for(int i = 0;i < s1.size();i++)
	{
		if(s1[i] != s2[i]) 
			ans++;
	}
	 
	cout << ans;
	return 0;	
} 
