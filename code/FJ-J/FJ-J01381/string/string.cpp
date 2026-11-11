#include<iostream>
#include<bits/stdc++.h>
using namespace std;
# define r return
int n;
long long number[100000000];
char zimu[200100];
string s;
string res;
long long cnt;
int main()
{

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	
	for(int i=1;i<=n;i++)
		cin>>number[i]>>zimu[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=number[i];j++)
			s=s+zimu[i];
	}
	res=s;
	reverse(s.begin(),s.end());
	if(s==res)
	{
		cout<<0;
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]!=res[i])
				cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

