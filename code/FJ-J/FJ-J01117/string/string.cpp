#include<bits/stdc++.h>
using namespace std;
bool isHuiwenString(string s)
{
	string s1=s;
	reverse(s.begin(),s.end());
	if(s==s1)return 1;
	return 0;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[200005]={};
	long long sum=0,cnt=0;
	char c[200005]={};
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)s+=c[i];
		sum+=a[i];
	}
	if(isHuiwenString(s))
	{
		cout<<0;
		return 0;
	}
	for(int i=0,j=sum-1;i<=j;i++,j--)
	{
		if(s[i]!=s[j])cnt++;
	}
	cout<<cnt;
	return 0;
}