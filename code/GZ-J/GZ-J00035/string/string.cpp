//GZ-J00035  都匀市第三中学  潘彦旭  
#include <iostream> 
using namespace std;
int a[200086];
char b[200086];
int fun1(string s)
{
	int ans=0;
	for(int i=0;i<s.length()/2;i++)
		if(s[i]!=s[s.length()-i-1])
			ans++;
	return ans;
}
int fun2(string s)
{
	int ans=0;
	for(int i=0;i<s.length()/2;i++)
		if(s[i]!=s[s.length()-1])
			ans++;
	return ans;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<a[i];j++)
			s+=b[i];
	}
	if(s.length()%2==0)
	{
		cout<<fun1(s);
		return 0;
	}
	else if(s.length()%2==1)
	{
		cout<<fun2(s);
	}
	return 0;
}

