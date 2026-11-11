#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a,a+n);
		cout<<a[n-1];
	}
	return 0;
}
