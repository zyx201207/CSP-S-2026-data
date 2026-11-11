#include <bits/stdc++.h> 
using namespace std;
string s,s1;
int n,ai,ls,m;
char ci;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ai>>ci;
		ls+=ai;
		for(int j=0;j<ai;j++)
			s+=ci;
	}
	for(int i=0;i<=ls;i++)
	{
		s1[i]=s[ls-i];
	}
	for(int i=0;i<ls;i++)
	{
		if(s1[i]!=s[i])
			m++;		
	}
	cout<<m-1;	
	return 0;
}
