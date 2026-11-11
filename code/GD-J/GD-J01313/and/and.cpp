#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		int b;
		cin>>b;
		if(i<m) a[i]=b;
		else
		{
			sort(a,a+m);
			a[0]=b;
		}
	}
	for(int i=m-1;i>0;i--)
	{
		a[i-1]=a[i-1]&a[i];
	}
	cout<<a[0];
	return 0;
}
