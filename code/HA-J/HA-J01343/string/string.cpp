#include<bits/stdc++.h>
using namespace std;
int a[100000005];
char b[100000005];
string s;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=b[i];
		}
	}
	int k=0,n=s.size()-1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s[n-i])
		{
			s[i]=s[n-i];
			k++;
		}
	}
	cout<<k;
	return 0;
} 
