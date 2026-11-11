#include<bits/stdc++.h>
using namespace std;
int n,m,a[200009];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int minn=1e9;
	for(int i=n;i>n-3;i--)
	{
		if(a[i]<minn)minn=a[i];
	}
	cout<<minn;
	return 0;
}
