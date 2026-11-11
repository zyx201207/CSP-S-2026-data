#include<bits/stdc++.h>
using namespace std;
string s;
int n,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		for(int j = 1;j<=a;j++) s+=c;
	}
	for(long unsigned int i = 0;i<s.size();i++)
	{
		if(s[i]!=s[s.size()-i]) break;
		else 
		{
			cout<<0;
			return 0;
		}
	}
	for(long unsigned int i = 0;i<s.size();i++) 
	{
		if(s[i]!=s[s.size()-i]) ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
