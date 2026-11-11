#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+10];
	int c[n+10];
	int d[n+10];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	return 0;
 } 
