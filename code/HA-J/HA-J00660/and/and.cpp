#include <bits/stdc++.h>
using namespace std;
int n,m,f;
long long a[200005],v[200005];

void er(int a)
{
    er(a/2);
	v[f++]=a%2;
}
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
		er(a[i]);
	}
	cout<<a[n-m];
	return 0;
}
