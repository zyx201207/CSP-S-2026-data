#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a[100005];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a[0],a[n-1]);
	cout<<a[n-m];
}
