#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;
string s="",s_add;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>a>>s_add;
		while(a--)s=s+s_add;
	}
	for(int i=0,j=s.size()-1;j>=i;i++,j--)
	{
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
} 
