#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200005],ans;
bool b(unsigned long long x,unsigned long long y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,b),ans=a[1];
	for(int i=2;i<=m;i++) ans&=a[i];
	cout<<ans;
	return 0;
}
