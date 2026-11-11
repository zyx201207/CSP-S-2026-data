#include <bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i] >> c[i];
	}
	string s;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i];j++)
		{
			s=s+c[i];
		}
	}
	int ss=0;
	s=" "+s;
	int l=1,r=s.size()-1;
	while(l<r)
	{
		if(s[l]!=s[r])
		{
			ss++;
		}
		l++,r--;
	}
	cout << ss;
	return 0;
}
