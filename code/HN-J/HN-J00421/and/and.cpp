#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
struct wei{
	long long a,top_bit;
}h[200010];
bool cmp(wei x,wei y){
	if(x.top_bit>y.top_bit) return x.top_bit>y.top_bit;
	else return x.a>y.a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++) scanf("%lld",&h[i].a);
	for(long long i=1;i<=n;i++){
		long long k=h[i].a,cnt=0;
		while(k){
			k/=2;
			cnt++;
		}
		h[i].top_bit=cnt;
	}
	sort(h+1,h+1+n,cmp);
	ans=h[1].a,--m;
	long long x=2;
	while(m--){
		ans&=h[x++].a;
	}
	printf("%lld",ans);
	return 0;
}

