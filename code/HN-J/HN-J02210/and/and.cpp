#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
		if(i==1)cnt=a[i];
		else cnt=cnt&a[i];
	}
	sort(a+1,a+n+1);
	int we=0;
	for(int i=n;i>=1;i--)
	{
		if(a[i]==a[n])we++;
		else break;
	}
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	if(m==n-1)
	{
		cout<<a[2];
		return 0;
	}
	if(m==n)
	{
		cout<<cnt;
		return 0;
	}
	if(m==2)
	{
		cout<<(a[n]&a[n-1]);
		return 0;
	}
	if(m<=we)cout<<a[n];
	else cout<<a[n%m];
	return 0;
 } 
