#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll x[N];
char c[N];
ll n;
int main(){
	freopen("string.in""r",stdin);
	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
	   scanf("%lld",&x[i]);
	   scanf("%s",&c[i]);
	}
	ll ans=0;
	ll l=0,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			if(x[l]>x[r]){
				ans+=x[r];
				x[l]-=x[r];
				r--;
			}
			else if(x[r]>x[l]){
				ans+=x[l];
				x[r]-=x[l];
				l++;
			}
			else{
				ans+=x[r];
				r--;
				l++;
			}
		}
		if(c[l]==c[r]){
			if(x[l]>x[r]){
				x[l]-=x[r];
				r--;
			}
			else if(x[r]>x[l]){
				x[r]-=x[l];
				l++;
			}
			else{
				r--;
				l++;
			}
		}
		
	}
	printf("%lld",ans);
	return 0;
}
