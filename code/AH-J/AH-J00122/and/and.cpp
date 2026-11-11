#include<bits/stdc++.h>
using namespace std;
int a[1000005],s;
bool cmp(int x,int y)
{
	return x>y;
}
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
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)
	{
		s=a[i-1]&a[i];
	}
	cout<<s;
}
                                              
