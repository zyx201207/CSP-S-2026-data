#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,x,a[200005],sum=0;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]and a[i-1] >= sum)
		{
			sum= a[i];
		}
	}
	cout <<sum;
}
