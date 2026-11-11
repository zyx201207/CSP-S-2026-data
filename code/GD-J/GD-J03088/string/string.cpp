#include<iostream>
using namespace std;
int main()
{
	long long n,a,num=0,b=0;
	cin>>n;
	string s,x,s1;
	for(int i=0;i<n;i++)
	{
		cin>>a>>x;
		b+=a;
		for(int j=0;j<a;j++)
		s+=x;
	}
	for(int i=b-1;i>b/2;i--)
	{
		s1+=s[i];
	}
	for(int i=0;i<b/2;i++)
	{
		if(s[i]!=s1[i])
		num++;
	}
	cout<<num;
	return 0;
}
