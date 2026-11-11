#include<bits/stdc++.h>
using namespace std;
long long a[200001];
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,s=2e31-1;
	cin>>n>>m;
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	sort(a,a+n,cmp);
	for(int i=0;i<m;i++)
	{
		s=s&a[i];
	}
	cout<<s;
	return 0;
}
