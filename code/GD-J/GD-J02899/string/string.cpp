#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll ans=0,num=0;
	int a;
	char s;
	string v;
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		int x;
		cin>>x>>s;
		num+=x;
		for(int i=1;i<=x;i++)
		{
			v+=s;
		}
	}
	for(int i=0;i<(num+1)/2;i++)
	{
		char x=v[i],y=v[num-i-1];
		if(x!=y) ans++; 
	}
	cout<<ans; 
	return 0;
} 
