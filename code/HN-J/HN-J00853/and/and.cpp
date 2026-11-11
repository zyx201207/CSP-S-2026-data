#include<bits/stdc++.h>
using namespace std;
int n,m,min_=2e9;
int a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		min_=min(min_,a[i]);
	}
	cout<<min_;
	return 0;
}
