#include<bits/stdc++.h>
using namespace std;
string s; 
string a;
int n,ans,x;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>a;
		for(int j=1;j<=x;j++)
		{
			s+=a; 
		}
	}
	for(int i=0;i<s.length()/2;i++)
	{
		int j=n-i;
		if(s[i]!=s[j])
		{
			ans++;
			s[j]=s[i];
		}
	}
	cout<<ans<<endl;
	return 0;
	//I love CCF
}
