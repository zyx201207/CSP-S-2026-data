#include<bits/stdc++.h>
using namespace std;
int n;
long long a[20001],ma=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]&a[j]>ma)	ma=a[i]&a[j];
		}
	}
	cout<<ma;
	return 0;
}
