#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	int n,m,a[999],maxa;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
	{
		maxa=max(maxa,a[i]&a[j]);
	}	
	}
	cout<<maxa;
}
