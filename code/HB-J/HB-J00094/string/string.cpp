#include  <bits/stdc++.h>
using namespace std;
long long n,ans,a,id;
string c,s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a >> c ;
		string p=c;
		for(int j=1;j<a;j++)
		{
			c=c+p;
		}
		s=s+c;
	}
	int len=s.size();
	for(int i=len-1;i>=len/2;i--)
	{
		if(s[id++]!=s[i])
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
