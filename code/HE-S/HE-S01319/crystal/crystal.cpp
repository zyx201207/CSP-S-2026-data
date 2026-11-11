#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int cnt=0;
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i]!=a[i+1])
			{
				a[i]=a[i+1];
				cnt++;
			}
			
		}
	}
	cout<<cnt;
	return 0;
} 
