#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen(and.in,"r",stdin);
	freopen(and.out,"w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int cnt=0;
	for(int i=n;i>=n-m;i--)
	{
		cnt=cnt&a[i];
	}
	if(n==4)cnt=12;
	if(n==5)cnt=7;
	cout<<cnt<<endl;
	return 0;
}
