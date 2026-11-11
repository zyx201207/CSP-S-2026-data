#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	string s = "";
	int n;
	cin >> n;
	while (n--)
	{
		int a; string c;
		cin >> a >> c;
		while (a--)
		{
			s+=c;
		}
	}
	string t = "";
	for (int i = s.size()-1; i >= 0; i--)
	{
		t += s[i];
	}
	if (s == t)
	{
		cout << 0;
		return 0;
	}
	cout << s.size()/2; 
	return 0;
 } 
