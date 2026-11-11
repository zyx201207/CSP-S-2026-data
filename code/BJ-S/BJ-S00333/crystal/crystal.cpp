#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[1000010];
ll maxn=1;
ll fuzhi,sum=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+1+n);
	for(ll i=n;i>1;i--){
		fuzhi=m;
		ll x=i-1;
		while(fuzhi>0&&x>0){
			if(fuzhi>=arr[i]-arr[x]){
			sum++;
			fuzhi-=arr[i]-arr[x];
			x--;
			}else{
			fuzhi=0;
			}
		}
		maxn=max(maxn,sum);
		if(maxn>=i){
		break;
		}
		sum=1;
	}
	cout<<maxn;
	return 0;
}
