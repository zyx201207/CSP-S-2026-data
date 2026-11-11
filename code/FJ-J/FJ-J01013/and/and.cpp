#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],m,ans;
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ans=a[n-m+1];
	for(int i=n-m+1;i<=n;i++){
		ans=(ans)&(a[i]);
	}
	cout<<ans<<'\n';//Can kkksc03 help me AC this problem?
	return 0;
} 
