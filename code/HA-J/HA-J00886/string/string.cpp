#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string s="";
	for (int i=1;i<=n;i++)
	{
		int a;
		char sc;
		cin >> a >> sc;
		s.append(a,sc);
	}
	long long cnt=0;
	for (int i=0;i<=s.size()/2;i++)
	{
		if (s[i]!=s[s.size()-i-1]) cnt++;
		
	}
	cout << cnt;
	
	return 0;
}

