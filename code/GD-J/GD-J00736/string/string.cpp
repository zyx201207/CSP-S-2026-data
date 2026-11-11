#include<bits/stdc++.h>
using namespace std;
long long n,a;
char c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	string s1 = "";
	while(n--)
	{
		scanf("%lld%c",&a,&c);
		while(a--) s1 += c; 
	}
	string s = s1;
	reverse(s1.begin(),s1.end());
	if(s == s1)
	{
		cout << 0;
		return 0;
	}
	long long j = s.size(),ans = 0;
	for(long long i = 0;i < j;i++)
	{
		if(s[i] != s[j]) ans++;
		j--;
	}
	printf("%lld",ans);
	return 0;
}
