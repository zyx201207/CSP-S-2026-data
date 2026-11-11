//GZ-J00458 邓可为 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = (2*1e5)+ 10;
ll n,m,a[N],ans;
void fun(ll k,ll x,ll y){
	if(y==0) {
		ans = max(ans,k);
		return; 
	}
	for(int i=x;i<=n-y+1;i++){
		fun(k&a[i],i+1,y-1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n-m+1;i++){
		fun(a[i],i+1,m-1);
	}
	printf("%lld\n",ans); 
	return 0;
} 
