#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],f[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(m==1)cout<<a[n];
	else cout<<a[n-m+1];
	return 0;
}
