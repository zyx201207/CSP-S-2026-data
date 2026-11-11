#include<bits/stdc++.h>
using namespace std;
int n;
double m;
int i;
int mans=0;
long long a[1000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	double l=0;
	for(i=1;i<=n;i++)
	{
		l+=a[i];
		if((l+m)/i<a[i+1])break;
	}
	printf("%d",i+1);
}
