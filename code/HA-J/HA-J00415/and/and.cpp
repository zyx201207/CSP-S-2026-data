#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int a[200005];
long long maxf=-10000;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		long long chu=a[i];
		for(int j=i+1;j<=i+m-1;j++)
		{
			chu&=a[j];
		}
		maxf=max(chu,maxf);
	}
	cout<<maxf;
}
