#include<bits/stdc++.h>
using namespace std;
int n,m,b;
int a[200325];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n-1;i++)
	{
		if(a[i]<a[i+1])
		{
			b=a[i];
			a[i]=a[i+1];
			a[i+1]=b;
		}	
	}
	cout<<a[m+1];
	return 0;
}

