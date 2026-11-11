#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,f,d;
ll a[100005]; 
void solve10(){
	if(f==0){
		cout << (long long)sqrt(m*2)+1;
	}else{
		ll ans=0,ansk=1e18;
		for(int i = d;i <= 2e8;i+=d){
			ll x=(i-d)/d+1;
			ll s=(d+i)*x/2;
			if(m-s >= 0 && m-s < ansk){
				ans=x+1;
				ansk=m-s;
			}
		}
		cout << ans;
	}
	
}
int main(){
	freopen("crystal.in", "r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i]!=i)f=1;
		if(i!=1)d=a[i]-a[i-1];
	}
	solve10();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

