#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll> num(n+3,-1);
	for(ll i=0;i<n;i++) cin>>num[i];
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			if(num[j]>num[i]){
				ll temp=num[i];
				num[i]=num[j];
				num[j]=temp;
			}
		}
	}
	cout<<num[m-1];
	return 0;
}
