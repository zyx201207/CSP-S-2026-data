#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,m,a[N],ans;
bool being[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		being[i]=true;
	}
	ll bit=(1ll<<30);
	for(;bit>=1;bit>>=1){
		ll cnt=0;
		for(int i=1;i<=n;i++){
			if(!being[i]) continue;
			if(a[i]&bit) ++cnt;
 		}
 		if(cnt<m) continue;
 		else{
		 	ans+=bit;
 			for(int i=1;i<=n;i++){
 				if(!being[i]) continue;
 				if(!(a[i]&bit)) being[i]=false;
			}
		}
	} cout<<ans;
	return 0;
} 
