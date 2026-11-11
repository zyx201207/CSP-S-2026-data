#include<bits/stdc++.h>
using namespace std;
string s4,s1,s2,s3;
int f(string s)
{
	int sum=0;
	for(int i=0;i<2;i++)
	{
		sum*=10;
		sum+=s[i]-'0';
	}
	return sum;
}
int jj(char k,char l)
{
	int op=0,po=0;
	if( k=='A'||k=='B'||k=='C')
	{
		op=1;
	}
	else op=0;
	if( l=='A'||l=='B'||l=='C')
	{
		po=1;
	}
	else po=0;
	if(op==po)return 1;
	else return 0;
}
int main()
{
	freopen("ÂÃÓÎ£¨travel£©.in","r",stdin);
	freopen("ÂÃÓÎ£¨travel£©.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	int n=f(s1),m=f(s3);
	int cnt=f(s2),ans=f(s4);
	char k=s2[2],l=s4[2];
	int pl=max(k,l),pk=min(k,l);
	if (n==m)cout<<1;
	else cout<<0;
	if (cnt==ans&&n==m)cout<<1;
	else cout<<0;
	if (cnt==ans&&jj(k,l)&&n==m)cout<<1;
	else cout<<0;
	if(jj(k,l)&&pl-pk==1&&ans==cnt&&n==m)cout<<1;
	else cout<<0;
	return 0;
 } 
