#include<bits/stdc++.h>
using namespace std;
string s;
int ans;
int main()
{
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	int n,a;
	char c;
	int si=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++)
			s[++si]=c;
	}
	int m=si-1;
	for(int i=1;i<=si/2;i++)
	{
		if(s[i]!=s[i+m])ans++;
		m-=2;
	}
	cout<<ans;
	return 0;
 } 
