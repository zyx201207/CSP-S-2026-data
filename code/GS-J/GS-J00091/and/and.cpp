#include<iostream>
using namespace std;
int a[10000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int x,n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m-1;i++)
	{
		x=(a[i]||a[i+1]);
	}
	cout<<x;
	return 0;
}
