#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	vector<char> s;
	s.reserve(100000);
	int l,s_=0;
	cin >> l;
	for(int i=0;i<l;i++)
	{
		int n;
		char s__;
		cin >> n >> s__;
		for(int i=0;i<n;i++)
		{
			s.push_back(s__);
		}
		s_+=n;
	}
	cout << s_;
	int ans=0,j=s_-1;
	for(int i=0;i<j;i++)
	{
		if(s[i]!=s[j])
		{
			ans++;
		}
		j--;
	}
	cout << ans;
	return 0;
}
