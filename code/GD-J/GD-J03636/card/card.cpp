#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;
ll n,m,ar[N],st[N],dp[N];
map<ll,ll> mp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	for(int i=1;i<=n;i++){
		ll pos=0;
		mp.clear();
		for(int j=i;j<=n;j++){
			if(mp[ar[j]]){
				ll f=ar[j];
				while(st[pos]!=f){
					mp[st[pos]]=0;
					st[pos]=0;
					pos--;
				}
			}
			else{
				st[++pos]=ar[j];
				mp[ar[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(mp[j]) dp[j]++;
		}
		for(int i=1;i<=pos;i++) st[pos]=0;
	}
	for(int i=1;i<=m;i++){
		cout<<dp[i]<<" ";
	}




	return 0;
}

