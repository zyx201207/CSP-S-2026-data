#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,T;
const int N=2e6+5;
ll n,d,a[N];
void solve(){
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(c==11||c==12){
		if(d<2*(a[2]-a[1])){
			printf("0\n");
			return;
		}
		printf("%lld\n",max((long long)0,n-(2*(d/(a[2]-a[1]))-1)));
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		solve();
	}
	return 0;
}
/*
11 1
4 7
7 14 21 28
*/
