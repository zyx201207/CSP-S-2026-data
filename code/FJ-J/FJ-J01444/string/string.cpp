#include <bits/stdc++.h>
using namespace std;
int n,x;
long long len,ans;
string ch,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> x >> ch,len += x;
		for(int j = 1;j <= x;j++) s += ch;
	}
	for(long long i = 0,j = len-1;i < len/2;i++,j--) 
		if(s[i] != s[j]) ans++;
	cout << ans;
	return 0;
}
