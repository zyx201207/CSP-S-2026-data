#include<iostream>
#include<cstdio>
using namespace std;
int a[1000000],b[1000000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	b[a[n]]=n;
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
