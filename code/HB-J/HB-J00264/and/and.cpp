#include <bits/stdc++.h>
using namespace std;

long long n,m,a[200005],f[200005],ans=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],f[i]=f[i-1]&a[i];
	for(int i=1;i<=n;i++) ans=max(ans,f[i+m]-f[i]);
	cout<<ans;
	return 0;
}
