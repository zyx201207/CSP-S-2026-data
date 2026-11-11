#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN = 2000010;
ll c,t; 
ll n,d;
ll a[MAXN],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%lld %lld" ,&c,&t);
	while(t--){
		ans = 0;
		memset(a,0,sizeof(a));
		scanf("%lld %lld" ,&n,&d);	
		for(int i = 1;i<=n;i++) { scanf("%lld",&a[i]); }
		if(a[2] - a[1] > d || a[n] - a[1] <= d){
			cout << 0 << endl;
			printf("0 \n"); 
			continue;
		}
		if(c == 11 || c == 12){
			ll cha = a[2] - a[1];
			ll maxnn = d/cha;
			if(maxnn >= 2) ans = n-(maxnn<<1)+1;
			cout << ans << endl;
			continue;
		}
			
	}
	return 0;
} 
