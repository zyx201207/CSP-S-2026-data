#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a,ans;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	s=" ";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)s+=c;
	}
	for(int i=1;i<=(-1+s.size())/2;i++)
	{
		if(s[i]!=s[(-1+s.size())-i+1])ans++;
	}
	cout<<ans;
	return 0;
} //3 2 a 2 b 1 c
