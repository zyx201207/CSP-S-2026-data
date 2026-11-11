#include <bits/stdc++.h>
using namespace std;
string s;
long long a[20000010];
char c[20000010];
int n;
unsigned long long sum[20000010];
unsigned long long all;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		for(int j = 1;j <= a[i];j++)
		{
			s+=c[i];
		}
	}
	unsigned long long cnt = 0;
	int l = 0,r = s.size()-1;
	while(l <= r)
	{
		if(s[l]!=s[r])
		{
		cnt++;
		}
		l++;
		r--;
	}
	cout << cnt;
	return 0;
}