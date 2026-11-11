#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	vector<ll> card(n,0),sum(m+5,0);
	for(ll i=0;i<n;i++) cin>>card[i];
	for(ll i=0;i<n;i++){
		vector<ll> game;
		for(ll j=i;j<n;j++) game.push_back(card[j]);
		for(ll j=0;j<game.size();j++){
			for(ll k=j;k<game.size();k++){
				for(ll l=k+1;l<game.size();l++){
					if(game[l]==game[k]&&game[l]>0&&game[k]>0){
						for(ll m=k;m<l;m++) game[m]=0;
						break;
					}
				}
			}
		}
		for(ll j=0;j<game.size();j++) sum[game[j]]++;
	}
	for(ll i=1;i<=m+1;i++){
		if(sum[i]>0) cout<<sum[i]<<" ";
	}
	return 0;
}
