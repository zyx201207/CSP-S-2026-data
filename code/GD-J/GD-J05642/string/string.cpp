#include <iostream>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++)
	{
		 int a;
		 char c;
		 cin>>a>>c;
		 while(a--)
		 s+=c;
	}
	string ss="";
	for(int i=s.size()-1;i>=0;i--)
	{
		ss+=s[i];
	}
	for(int i=0;i<s.size();i++)
	{
		if(ss[i]!=s[i])
		{
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
