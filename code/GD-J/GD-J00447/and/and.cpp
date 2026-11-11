#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b)
{
	return a>b;
}
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	long long MAX=0;
	for(int i=0;i<n;i++)
	{
		long long ans=a[i];
		for(int j=1;j<m;j++)
		{
			ans=a[j]&ans;
		}
		MAX=max(ans,MAX);
	}
	cout<<MAX;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
