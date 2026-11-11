#include <bits/stdc++.h>
using namespace std;
int n,a[200050];
char b[200050];
int c=0;
queue<long long> q;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	if(n==1)cout<<0;
	else if(n==2)
	{
		if(b[1]==b[2])cout<<0;
		else
		{
			c=a[1]+a[2];
			cout<<c/2;
		}
	}
	else
	{
		c=0;
		for(int i=1;i<=n;i++)
		{
			c+=a[i];
		}
	 	cout<<c/2; 
	}
	return 0;
} 
