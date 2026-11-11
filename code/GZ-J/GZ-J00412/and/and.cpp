//GZ-J00412 贵阳市观山湖区普瑞学校 袁雅琪
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long b,c=0,d,n,m,i,j,h=0;

	cin>>n>>m;
	int a[n+1]={};
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
cout<<a[m-1];
	return 0;
}
