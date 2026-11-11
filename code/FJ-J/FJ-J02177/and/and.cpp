#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5;
int n,m,a[N];
bool cmp(unsigned long long c,unsigned long long d)
{
	return c>d;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[m];
	return 0;
}