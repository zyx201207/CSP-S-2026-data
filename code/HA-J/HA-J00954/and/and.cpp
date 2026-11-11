#include<bits/stdc++.h>
using namespace std;
const int N=219402;
int a[N];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int x=a[m];
	for(int i=m;i>=n-m+1;i--)
	{
		x&=a[i];
	}
	cout<<x;
	return 0;
}
