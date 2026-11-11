#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	int cnt=0;
	for(int i=1;i<=n/2;i++)
	{
		cnt+=a[i];
	}
	cout<<cnt<<" ";
	cout<<a[1]<<" ";
	cout<<a[n]+a[n-1];
}
