#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,a[10];
string s,s1;
char s2,s3;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>n>>s>>m>>s1;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(isdigit(s[i]))
		{
			l*=10;
			l+=(s[i]-'0');
		}
		if(s[i]>='A'&&s[i]<='F')
		{
			s2=s[i];
		}
	}
	for(int i=0;i<=s1.size()-1;i++)
	{
		if(isdigit(s1[i]))
		{
			r*=10;
			r+=(s1[i]-'0');
		}
		if(s1[i]>='A'&&s1[i]<='F')
		{
			s3=s1[i];
		}
	}
	if(n==m)
	{
		a[1]=1;
	}
	if((n==m)&&(l==r))
	{
		a[2]=1;
	}
	if((n==m)&&(l==r)&&((s2>='A'&&s2<='C'&&s3>='A'&&s3<='C')||(s2>='D'&&s2<='F'&&s3<='F'&&s3>='D')))
	{
		a[3]=1;
	}
	if((n==m)&&(l==r)&&(s2=='A'&&s3=='B'||s2=='B'&&s3=='A'||s2=='B'&&s3=='C'||s2=='C'&&s3=='B'||s2=='D'&&s3=='F'||s2=='F'&&s3=='D'))
	{
		a[4]=1;
	}
	for(int i=1;i<=4;i++)
	{
		cout<<a[i];
	}
	cout<<endl;
	return 0;
} 
