#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,num=1;
	cin>>n>>m;
	if(n<=5000){
		ll a[5001];
		for(ll i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=1;i<n;i++){
			if(a[i]==a[i-1]){
				num++;
				continue;
				
			}
			ll jk=(a[i]-a[i-1])*num;
			if(m>=jk) {
				m-=jk;
				num++;
			}
			else{
				cout<<num;
				return 0;
			}
		}
	}
	else{
		ll k1;cin>>k1;
		for(ll i=1;i<n;i++){
			ll k;cin>>k;
			ll los=(k-k1)*num;
			if(k==k1){
				num++;
				continue;
				k1=k;
			}
			else if(m>=los){
				m-=los;
				num++;
				k1=k;
			}
			else if(m<los) {
			    cout<<num;
			    return 0;
			}
		}
	}
} 
