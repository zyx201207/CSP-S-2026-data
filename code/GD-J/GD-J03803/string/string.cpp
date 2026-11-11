#include<bits/stdc++.h>
using namespace std;
int p[200005],n;
long long l,ans;
char c[200005]; 
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i]>>c[i];
		for(int j=0;j<p[i];j++)
		{
			s+=c[i];
		}
		l+=p[i];
	}
	for(int i=1;i<=l/2;i++)
	{
		if(s[i-1]!=s[l-i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
 } 
