#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,ma=0,a[200010],m;
void s(int cnt,int shu)
{
	if(cnt==m)
	{
		ma=max(ma,shu);
		return;
	}
	cnt++;
	for(int i=n;i<m;i++)
	{
		s(cnt,shu&a[i]);
	}
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
	for(int i=0;i<n;i++)
	{
		s(0,a[i]);
	}
	cout<<ma;
    return 0;
}
