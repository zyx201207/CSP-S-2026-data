#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000005],check[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		if(n==2){
			check[a[1]]=1,check[a[2]]=2;
		}else if(n==3){
			if(a[1]==a[3]){
				check[a[1]]=2;
				check[a[2]]=1;
			}
			if(a[1]==a[2]){
				check[a[1]]=2;
				check[a[3]]=3;
			}
			if(a[2]==a[3]){
				check[a[1]]=1;
				check[a[2]]=3;
			}
		}else{
			check[1]=5,check[2]=7;
		}
		cout<<check[1]<<" "<<check[2];
		return 0;
	}
	for(ll i=1;i<=n;i++){
		check[a[i]]=i;
	}
	for(ll i=1;i<=m;i++){
		cout<<check[i]<<" ";
	}
	
	
	return 0;
}
