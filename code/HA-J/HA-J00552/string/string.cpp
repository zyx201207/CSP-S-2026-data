#include<bits/stdc++.h>
using namespace std;
int n,t,sum=0,num=0;
char ch;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t>>ch;
		for(int j=1;j<=t;j++)
			s+=ch;
	}
	for(int i=1,j=s.size();i<=ceil(s.size()/2),j>=i;i++,j--)
	{
		if(s[i]==s[j])
		{
			s[j]=s[i];
			continue;
		}
		num++;
	}
	cout<<num;
	
	return 0;
}
