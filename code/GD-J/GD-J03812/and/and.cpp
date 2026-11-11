#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2*1e5+10;
LL n,m,a[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<LL>());
	ans=(a[1]&a[2]);
	for(int i=3;i<=m;i++){
		ans=(ans&a[i]);
	}
	cout<<ans;
	
	return 0;
}
