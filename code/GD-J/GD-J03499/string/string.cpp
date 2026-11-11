#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[1000000000];
long long num=1;
unsigned long long cnt;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for(long long i=1; i<=n; i++)
	{
		long long a;
		char c;
		cin >> a >> c;
		for(long long j=1; j<=a; j++)
		{
			s[num]=c;
			num++;
		}
	}
	num--;
	for(long long i=1; i<=num; i++)
	{
		if(s[i]!=s[num-i+1]) cnt++;
	}
	cout << cnt/2;
	return 0;
}
