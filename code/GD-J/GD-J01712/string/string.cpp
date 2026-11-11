#include <bits/stdc++.h>
using namespace std;
long long n,m,l,r,ans,k=1;
char a;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(long long i=1;i<=n;i++)
	{
		cin >> m >> a;
		for(long long j=1;j<=m;j++)
		{
			s+=a;
		}
	}
	//cout << s;
	r=s.length()-1;
	//cout <<endl<< r << " " << s[l] << " " << s[r-1];
	while(l<=r)
	{
		if(s[l]!=s[r])ans++;
		l++,r--;
	}
	cout << ans;
	return 0;
 } 
