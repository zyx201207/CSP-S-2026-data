#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s=0,z=-1e9;
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++)
	{
		if(s!=m)
		{
			b[i]=a[i];
			s++;
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(b[i]>z)
		{
			z=b[i];
		}
	}
	cout<<z;
	return 0;
} 
