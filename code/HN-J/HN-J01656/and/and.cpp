#include<bits/stdc++.h>
using namespace std;
bool f(long long a,long long b) 
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	int q,i;
	long long ans;
	cin>>n>>m;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,f);
	ans=a[0];
	for(i=1;i<m;i++)
	{
		ans=ans&a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
 }
