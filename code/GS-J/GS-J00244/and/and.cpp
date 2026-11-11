#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],c;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i+=2)
		{
			int x=a[i]&&a[i+1];
			c=c&&x;
		}
		cout<<c;
		return 0;
	}
	return 0;
}
