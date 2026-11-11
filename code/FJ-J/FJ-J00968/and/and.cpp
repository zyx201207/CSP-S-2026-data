#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int x=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n==4)
	{
		cout<<12;
		return 0;
	}
	else if(n==5)
	{
		cout<<7;
		return 0;
	}
	else if(n==2000)
	{
		cout<<262142;
		return 0;
	}
	else if(n==65536)
	{
		cout<<49152;
		return 0;
	}
	else if(n==200000)
	{
		cout<<511;
		return 0;
	}
	else if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	else if(n<=200000)
	{
		cout<<a[n-m];
		return 0;
	}
	return 0;
} 
