#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+9;
ll n,m;
ll a[N];
bool c[N][32];
bool check(ll mid){
	ll tot=0;
	for(int i=1;i<=n;i++){
		if((a[i] & mid) == mid)tot++;
	}
	if(tot>=m)return true;
	else return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	ll i=1,j=(1<<30);
	while(i<=j){
		ll mid=(j-i)/2+i;
		if(check(mid))i=mid+1;
		else j=mid-1;
	}
	printf("%lld",i-1);
	return 0;
} 
/*

*/

