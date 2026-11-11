#include<bits/stdc++.h>
using namespace std;
long long a[200001],v=1,m;
long long z;
char b[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	m=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
	if(v>=m)
	break;
		if(a[v]>a[m])
		{
			if(b[v]!=b[m])
			z+=a[m];
			m--;
			a[v]-=a[m+1];
		}
		else if(a[v]<a[m])
		{
			if(b[v]!=b[m])
			z+=a[v];
			v++;
			a[m]-=a[v-1];
		}
		else
		{
			if(b[v]!=b[m])
			z+=a[v];
			v++;
			m--;
		}
	}
	cout<<z;
	return 0;
}
