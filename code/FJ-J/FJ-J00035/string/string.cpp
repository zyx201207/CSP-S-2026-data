#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	s+="N";
	for(int i=1;i<=n;i++)
	{
		int a;
		string b;
		cin>>a;
		cin>>b;
		for(int i=1;i<=a;i++)
		{
			s+=b;
		}
	}
	int ans=0;
	for(int i=1;i<=s.length()/2;i++)
	{
		if(s[i]!=s[s.length()-i])
		{
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
