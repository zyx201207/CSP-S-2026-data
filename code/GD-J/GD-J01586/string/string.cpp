#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	freopen(string.in,'r',stdin);
	freopen(string.out,'w',stdout);
	int l;
	cin>>l;
	int a[l+1]={0},z=0,t=0,o=0,e=0,k=0;
	char b[l+1];
	for(int i=0;i<l;i++)
	{
		cin>>a[i];
		cin>>b[i];
		if(b[i]==b[i-1]) k++;
		e+=a[i];
	}
	if(k==l-1)
	{
		cout<<0;
		return 0;
	}
	char s[e+1]={0},s1[e+1]={0};
	for(int i=0;i<l;i++)
	{
		for(int j=z;j<(z+a[i]-1);j++)
		{
			s[j]=a[i];
		}
		z+=a[i];
	}
	for(int i=0;i<z;i++)
	{
		s1[i]=s[i];
	}
	for(int i=z-1;i>=0;i--)
	{
		s[t]=s1[i];
		t++;
	}
	for(int i=0;i<z;i++)
	{
		if(s1[i]!=s[i])
		{
			s[i]=s1[i];
			o++;
		}
	}
	cout<<o;
}
