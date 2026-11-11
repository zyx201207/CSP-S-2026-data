#include<bits/stdc++.h>
using namespace std;
int n,s,a[200010],l,ax=0,man;
string b[200010],m[1000000100];
long long mmm;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i];i++)
		{
			m[i]=b[i];
			l++;
		}
	}
	int r=0,s=l;
	for(int i=0;i<=l/2;i++)
	{
		if(r!=s)
		{
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(ax<=a[i])
		{
			ax=a[i];
			man=i;
		}
	}
	for(int i=i;i<=n;i++)
	{
		mmm+=a[i];
	}
	cout<<mmm-a[man];
	return 0;
} 
