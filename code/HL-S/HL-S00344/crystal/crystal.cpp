#include<bits/stdc++.h>
using namespace std;
long long int a[500005],s[500005],ss[500005],n,m;
bool ch(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(ss[i]-ss[i-x]-s[i]*x<=m)
			return true;
	}
	return false;
}
int main()
{
	freopen("crystal.in ","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long int maxn=a[n/2];
	for(int i=1;i<=n;i++)
	{
		s[i]=maxn-a[i];
		ss[i]=ss[i-1]+s[i];
	}
/*	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<s[i]<<' ';
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<ss[i]<<' ';
	cout<<endl;*/
	long long int l=0;
	long long int r=n;
	while(l<r)
	{	
	
		if(l==r-1)
		{
			if(ch(r)) l++;
			else r--;
			continue;
		}
		long long mid=(l+r)/2;
		if(ch(mid)) l=mid;
		else r=mid-1;
		//cout<<l<<' '<<r<<endl;
		//cout<<l<<' '<<r<<endl;
		//cout<<l<<' '<<r<<endl;
	}
	cout<<l;
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/
