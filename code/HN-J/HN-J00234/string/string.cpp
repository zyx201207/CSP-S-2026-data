#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,total=0,wei=0,ans=0;
	cin>>n;
	int a[n];
	char b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	for(int i=0;i<n;i++) total+=a[i];
	char c[total]={};
	for(int i=0;i<n;i++) 
	{
		for(int j=0;j<a[i];j++)
		{
			c[wei]=b[i];
			wei++;
		}
	}
	for(int i=0;i<total/2;i++)
	{
		if(c[i]!=c[total-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
