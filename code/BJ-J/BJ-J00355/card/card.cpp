#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[1000010],brr[1001000],sum[1001000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>arr[i];
		brr[i]=arr[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			for(ll z=i;z<j;z++){
				if(brr[j]==brr[z]){
					for(ll q=z;q<j;q++){
						brr[q]=0;
					}
				}
			}
		}
		for(ll j=i;j<=n;j++){
			sum[brr[j]]++;
			}
		for(ll j=i;j<=n;j++){
		brr[j]=arr[j];
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
