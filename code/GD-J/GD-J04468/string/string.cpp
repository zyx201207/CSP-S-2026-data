#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mmm=2e5+200;
ll n;
ll a[mmm];
char c[mmm];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll ans=0;
	ll i=1;
	ll j=n;
	while(j>i){
		if(a[i]==a[j]){
			if(c[i]!=c[j]){
				ans+=a[i];
			}
			i++;
			j--;
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				if(c[i]!=c[j]){
					ans+=a[j];
				}
				j--;
			}else{
				a[j]-=a[i];
				if(c[i]!=c[j]){
					ans+=a[i];
				}
				i++;
			}
		}	
	}
	cout<<ans;
	return 0;
} 
