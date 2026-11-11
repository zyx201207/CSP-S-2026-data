#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b[99999990],cnt,ans,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		ll a;
		char c;
		cin>>a>>c;
		for(ll i=1;i<=a;i++){
			b[++cnt]=(c-'a');
		}
	}
	if(cnt%2==1){
		ll mid=(1+cnt)/2;
		for(ll i=1;i<=mid-1;i++){
			if(b[mid-i]!=b[mid+i]){
				ans++;
			}
		}
	}else{
		ll l=cnt/2,r=cnt/2+1;
		for(ll i=0;i<l;i++){
			if(b[l-i]!=b[r+i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
