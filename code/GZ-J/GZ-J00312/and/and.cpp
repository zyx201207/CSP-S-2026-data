//GZ-J00312,韦胤帆,贵阳市第十八中学
#include<bits/stdc++.h>
using namespace std;
long long n,a[100000],m,f,l;
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	f=a[0];
	for(int i=0;i<m;i++)
	{
		f=f&a[i];
	}
	cout<<f;
	return 0;
}
