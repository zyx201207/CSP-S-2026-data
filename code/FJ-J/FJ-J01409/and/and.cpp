#include<bits/stdc++.h>
using namespace std;

int a[200005];
int ans=0;

int main()
{
	fopen("and.in","r");
	fopen("and.out","w");
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	ans=a[n];
	for(int i=2;i<=m;i++)
	{
		ans=a[n+1-i]&ans;
	}
	cout<<ans;
	return 0;
} 
