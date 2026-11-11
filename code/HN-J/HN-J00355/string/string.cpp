#include<bits/stdc++.h>
using namespace std;
int d[101];
int main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0;
	cin>>n;
	char a[101];
	for(int i=1; i<=n; i++)
	{
		cin>>d[i];
		cin>>a[i];
	}
	for(int i=1; i<=n; i++)
	{
		if(a[i]=a[i]+1)
		{
			cout<<s;
			return 0;
		}
	}
	return 0;
}
