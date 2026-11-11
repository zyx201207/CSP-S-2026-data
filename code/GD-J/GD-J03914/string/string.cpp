#include <bits/stdc++.h>
using namespace std;
long long ans;
string s; 
void chack(string s)
{
	long long len = s.size() -1;
	for(long long i = 0 ; i < s.size()/2 ; i ++)if(s[i] != s[len-i]) ans ++;
	return ;
}
long long n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	scanf("%lld",&n);
	for(long long i = 1 ; i <= n ; i ++)
	{
		long long t;
		char c;
		cin >> t >> c;
		for(long long j = 1 ; j <= t ; j ++) s += c;
	}
	chack(s);
	printf("%lld",ans);
}
