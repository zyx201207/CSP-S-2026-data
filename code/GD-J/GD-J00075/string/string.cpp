#include<bits/stdc++.h>
using namespace std;

char a[200005] = {};
long long s[200005] = {};

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long sum = 0;
	int cnt = 0;
	for(int i = 1;i <= n;i++)
	{
		long long num;
		char ch;
		cin >> s[i] >> a[i];
	}
	int l = 1,r = n;
	long long mid = (l + r) / 2;
	for(int i = 1;l < r;i++)
	{
		int m = min(s[l],s[r]);
		if(a[l] != a[r])
		{
			sum += m;
		}
		s[l] -= m;
		s[r] -= m;
		if(!s[l]) l++;
		if(!s[r]) r--;
	}
	cout << sum << endl;
	return 0;
}
