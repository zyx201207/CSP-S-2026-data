#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and5.in","r",stdin);
	freopen("and5.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100000];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int p=a[n];
	for(int i=n-1;i>=n-m+1;i--)
	{
		p=p&a[i];
	}
	cout<<p<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
/*
4 2
3 15 12 12
5 3
2 31 3 1 15 7
*/
