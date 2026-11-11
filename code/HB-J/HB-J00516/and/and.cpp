#include<bits/stdc++.h>
using namespace std;

a[10000000];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	int n,m;
	cin>>n>>m;
	int maxx=-100;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i);
	}
	cout<<maxx;
	return 0;
}
