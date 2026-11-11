#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin >> n;
	
	string s;
	int len = 0;
	int a[200010];
	char c[200010];
	bool flag = 1;
	
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i] >> c[i];
		if(c[i] != c[i-1] && i != 1)
		{
			flag = 0;
		}
		len += a[i];
		s += a[i]*c[i];
	}
	if(flag == 1)
	{
		cout << 0;
		return 0;
	}
	int l = 0,r = len-1;
	int sum = 0;
	while(l < r)
	{
		if(s[l] != s[r])
		{
			sum++;
		}
		l++;
		r--;
	}
	cout << sum;
	return 0;
} 
