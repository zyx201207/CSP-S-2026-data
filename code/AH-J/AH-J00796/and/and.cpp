#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+5;
LL n,m,ans,a[N];            
bool cmp(const LL &x,const LL &y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	ans=a[1];
	for(LL i=2;i<=m;i++){
		ans=(ans&a[i]);
	}
	cout<<ans;
	return 0;
}
