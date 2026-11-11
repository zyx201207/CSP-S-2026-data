#include<bits/stdc++.h>
using namespace std;
int a[200001];char b[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long s=0,g=0,j;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d %c",&a[i],&b[i]);
		s=s+a[i];
	}
	for(long long i=1;i<=s/2;i++)
	{
		j=s-i;
		int i2=i;
		int i1=0,j1=0;
		while(i2>a[i1])
		{
			i1++;
			i2=i2-a[i1];
		}
		while(j>a[j1])
		{
			j1++;
			j=j-a[j1];
		}
		if(b[i1]!=b[j1]) g++;
	}
	cout<<g;
	return 0;
}
