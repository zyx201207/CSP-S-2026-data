#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m,l=0,s=1,mx=1,p;
	bool b=true;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long s1[n+5];
	for(int i=1;i<=n;i++) 
	{
		cin>>s1[i];
	}
	p=s1[2]-s1[1];
	for(int i=2;i<=n;i++)
	{
		if(s1[i+1]-s1[i]!=p)
		{
			b=false;
			break;
		}
	}
	if(b==true)
	{
		if(pow(n,2)<=m) cout<<n;
	}
	sort(s1+1,s1+n+1);
	for(int i=2;i<=n;i++)
	{
		if(l+(s1[i]-s1[i-1])*s<=m)
		{
			l=(s1[i]-s1[i-1])*s;
			s++;
			if(s>mx) mx=s;
		} 
		else
		{
			l=0;
			s=1;
			continue;
		}
	}
	cout<<mx;
	return 0;
} 
