#include<bits/stdc++.h>
using namespace std;
int n,m,a[1020100],sum,t;
bool mysort(int x,int y)
{
	return x>y;
}
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)
cin>>a[i];
sort(a+1,a+1+n);
for(int i=n;i>=m;i--)
{
	sum=a[n]&a[n-1]&a[n-2];
}
cout<<sum;

	return 0;
}
