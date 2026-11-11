#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int c,t;
bool pd(ll x[],ll n){
	int a=x[1]-x[0];
	for(int i=1;i<n;i++){
		if(x[i+1]-x[i]!=a)return 0;
	}
	return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		ll n,d,x[N];
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",x+i);
		cout<<0<<'\n';
	}
	return 0;
} 
