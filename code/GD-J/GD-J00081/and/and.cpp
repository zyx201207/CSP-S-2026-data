#include <bits/stdc++.h>
using namespace std;


struct iad{
	long long n,o = 0;
}l[22000];
bool cmp(iad a,iad b){
	if(a.o != b.o)
		return a.o > b.o;
	return a.n > b.n;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans = 0,x;
	scanf("%lld%lld",&n,&m);
	for(int i = 0;i < n;i ++){
		scanf("%lld",&x);
		l[i].n = x;
		int k = 0;
		while(x){
			l[i].o += x % 2;
			x /= 2;
		}
	}
	sort(l,l + n,cmp);
	ans = l[0].n;
	for(int i = 1;i < m;i ++){
		ans &= l[i].n;
	}
	printf("%lld",ans);
	return 0;
}
