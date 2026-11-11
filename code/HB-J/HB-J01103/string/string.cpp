#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;
int n;
string s="";
long long sum=0;
long long a[200005];
char c[200005];
int p;
void maxg()
{
	long long minn;
	for(int i=1;i<=n;i++)
	{
		minn=min(minn,a[i]);
	}
	string k=to_string(minn);
	p=0;
	for(int i=k.size()-1;i>=0;i--)
	{
		if(k[i]=='0') p++;
		else break;
	}
	for(int i=1;i<=n;i++)
	{
		a[i]/=(pow(10,p));
	}
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	long long maxn=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		maxn=max(a[i],maxn);
	}
	if(maxn>=100) maxg();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];j++)
		{
			s+=c[i];
		}
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[s.size()-i-1]) sum++;
	}
	string ans=to_string(sum);
	for(int i=1;i<=p;i++)
	{
		ans+="0";
	}
	cout<<ans;
	return 0;
}
