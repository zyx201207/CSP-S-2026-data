#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<a[0];
	return 0;
}
