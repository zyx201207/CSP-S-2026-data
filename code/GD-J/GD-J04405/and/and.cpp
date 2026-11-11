#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int max1=0;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		max1=max(a[i],max1);
	}
	cout<<max1;
	return 0;
}
