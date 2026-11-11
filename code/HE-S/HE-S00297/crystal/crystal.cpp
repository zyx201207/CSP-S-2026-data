#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;

long long n,m;
long long a[maxn]={};
long long ans=0,cnt=0;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		cnt+=abs(a[i]);
	}
	cnt=cnt/n+0.5;
	for(int i = 1;i <= n;i++)
	{
		if(a[i]<=cnt) ans++; 
	}
	cout<<ans<<endl;
	return 0;	
} 
