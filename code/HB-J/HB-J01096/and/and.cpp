#include<bits/stdc++.h>
using namespace std;
bool cmp(int a1,int a2)
{
	return a1>a2;
}
long long n,m,ans,a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++)
		ans=ans & a[i];
	cout<<ans;
}
