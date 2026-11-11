#include <bits/stdc++.h>
using namespace std;
long long n,l=0,r=-1;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		int a;char c;
		cin >> a >> c;
		for(int j = 1;j <= a;j++)	s+=c;
		r+=a;
	}
	long long ans = 0;
	while(l<=r)
	{
		if(s[l]!=s[r])	ans++;
		l++;
		r--;
	}
	cout << ans;
	return 0;
}
