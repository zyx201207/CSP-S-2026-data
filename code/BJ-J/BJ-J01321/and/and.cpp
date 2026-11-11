#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum=a[n-1];
	for(int i=1;i<m;i++)
	{
		int j=n-2;
		sum=a[j]|sum;
		j--;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
return 0;
}
