#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[900010];
//long long a2[900010];
long long b[900010];
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
		for(int j=i+1;j<=n;j++)
		{
			while(m)
			{
				b[i]=a[i]&a[j];
			}
		}
	}
	sort(b,b+n);
	for(int i=0;i<n;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<b[0];
	return 0;
}
