#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
struct Node{
	ll x,x_1;
}a[N];
ll Count_1(ll n){
	ll cnt=0;
	while(n){
		n&=(n-1);
		cnt++;
	}
	return cnt;
}
bool cmp(const Node &x,const Node &y){
	if(x.x_1!=y.x_1) return x.x_1>y.x_1;
	return x.x>y.x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].x);
		a[i].x_1=Count_1(a[i].x);
	}
	sort(a+1,a+n+1,cmp);
	printf("%lld",a[m].x);
	return 0;
}
