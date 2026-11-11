#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[10000010];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	sort(a+1,a+n+1,cmp);
	long long k=a[1];
	for(int i=1;i<=m;i++)
	{
		k&=a[i];
	}
	cout<<k;
	


	
	return 0;
}
