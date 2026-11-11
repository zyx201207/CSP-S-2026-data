#include<iostream>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,s2;
	int n,a;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c; 
	}
	string s0=s;
	for(int i=1;i<=n/2;i++)
	{
		s2+=s[i];
	}
	for(int i=n/2+1;i>1;i--)
	{
		s2+=s0[i];
	}
	int cnt=0;
	if(s2==s0)
	{
		cout<<"0";
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(s2[i]!=s0[i]) cnt++; 
	}
	cout<<cnt;
	return 0;
}
