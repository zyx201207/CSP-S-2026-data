#include<bits/stdc++.h>
using namespace std;

int n;
char s[200000000000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		long long a; char c;
		cin >> a >> c;
		while(a--)
		{
			 s[t++] = c;
		}
	}
	long long l = strlen(s);
	long long step = 0;
	for (long long i = 0; i < l / 2; i++)
	{
		for (long long j = l-1; j > i; j--)
		{
			if(s[i] != s[j]) step++;
		}
	}
	cout << step;
	return 0;
}
