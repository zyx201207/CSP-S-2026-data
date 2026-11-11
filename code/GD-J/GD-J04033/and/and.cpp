#include<bits/stdc++.h>
#define ll unsigned long long
const ll maxn=2e5+10;
using namespace std;
ll c[maxn];
ll a,b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(ll i=0;i<a;i++){
		cin>>c[i];
	}
	sort(c,c+a);
	ll t=0,ans=0;
	for(ll i=0;i<a;i++){
		t=c[i];
		for(ll j=0;j<b;j++){
			if(j%2==0){
				t=t&c[a-1-j];
			}else{
				ll y=t&c[j];
				ll e=t&c[a-1-j];
				t=max(y,e);
			}
		}
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
} 
