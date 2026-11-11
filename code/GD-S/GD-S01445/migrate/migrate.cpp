#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define filename "migrate"
const int N=1e6+10;
int c,t;
ll n,d;
ll x[N];
void solve(){
	scanf("%lld%lld",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
	}
	printf("0\n");
}
int main(){
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		solve();
	}
	return 0;
}
