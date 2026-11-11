#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<map>
#include<string>
#include<cstring>
using namespace std;
string s,s1,s2,s3;
map<string,int> mp;
int len,flag,a,b,n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>s;
		s1+=s;
		if(s1==s)
		{
			flag=1;
		}
		else
		{
			flag=0;
		}
		while(a--)
		{
			s2+=s;
		}
	}
	
	if(flag==1)
	{
		cout<<0;
		return 0;
	}
	len=s2.size();
	int t=len-1;
	for(int i=0;i<=len;i++)
	{
		s3[t--]+=s2[i];
	}
	if(s3==s2)
		cout<<0;
	return 0;
}










