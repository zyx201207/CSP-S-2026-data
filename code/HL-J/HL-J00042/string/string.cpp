#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000010];
char b[1000010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long sum=0;
	string s="";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++)
		{
			s+=b[i];
		}
	}
	string s1=s;
	for(int i=1;i<=n;i++)
	sum+=a[i];
	sum--;
	long long ans=sum;
	ans/=2;
	for(int i=ans;i<=sum;i++)
	{
		s1[i]=s1[sum-i];
	}
	if(s==s1){
		cout<<0;
		return 0;
	}
	long long cnt=0;
	for(int i=0;i<=sum;i++)
	{
		if(s1[i]!=s[i])cnt++;
	}
	cout<<cnt;
	return 0;
}
