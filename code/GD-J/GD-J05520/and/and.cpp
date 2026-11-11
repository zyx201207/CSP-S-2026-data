#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
 } 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[202250]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int x=a[1];
	for(int i=1;i<=m;i++)x=x&a[i];
	cout<<x;
	return 0;
}
