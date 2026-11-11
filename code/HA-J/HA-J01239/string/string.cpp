#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+2;
ll ans=1,num,sum=-1,tot;
struct p{
	int w;
	char s;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].w>>a[i].s;
		num+=a[i].w;
	}
	ll k=(num-1)/2;
	for(ll i=1;i<=n;i++){
		if(a[i].s==a[i+1].s){
			ans++;
		}else{
			sum++;
		}
	}
	if(ans==n){
		cout<<0;
		return 0;
	}else if(ans==1){
		cout<<(num-1)/2;
		return 0;
	}
	if(sum==1&&n%2==1){
		cout<<(num-1)/2;
		return 0;
	}else if(sum==1&&n%2==0){
		cout<<num/2;
		return 0;
	}
	return 0;
}
