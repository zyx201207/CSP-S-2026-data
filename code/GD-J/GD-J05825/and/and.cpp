#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int f(long long a,long long b)
{
	string s1,s2;
	while(a!=0)
	{
		s1+=char((a%2)+'0');
		a/=2;
	}
	while(b!=0)
	{
		s2+=char((b%2)+'0');
		b/=2;
	}
	long long len1=s1.size(),len2=s2.size();
	string s3;
	long long k2=len2-1,k1=len2-1;
	long long k=0;
	while(k2>=0)
	{
		if(s1[k1]==s2[k2]&&s1[k1]=='1'){
			s3+='1';k++;	
		}
		else if(k!=0){
		s3+='0';k++; 	
		}
		k1--;k2--;
	}
	long long len3=s3.size();
	long long num=0;
	for(int i=0;i<len3;i++)
	{
		if(s3[i]=='1'){
			num+=pow(2,len3-i-1);
		}
	}
	return num;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long num=a[n];
	for(long long i=n;i>=n-k+2;i--)
	{
		num=f(a[i],a[i-1]);
	}
	cout<<num; 
	return 0;
}
