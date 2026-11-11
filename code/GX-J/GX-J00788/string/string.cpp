#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long n,a[N],sum,s[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i]>>c[i];
	}
	if(n % 2 == 0)
	{
		for(int i = 1;i <= n;i++)
		{
			s[c[i] - '0'] += a[i];
		}
		sort(s + 'a',s + 'a' + 'z');
		cout << s['z'];
		return 0;
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			if(a[i] % 2 == 0&&s[c[i] - '0']==0)
			{
				sum++;
			}
			if(s[c[i]-'0'] == 0)
			{
				s[c[i]-'0']++;
			}
		}
		cout << sum;
	}
	
	return 0;
}
