#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5;
unordered_map<ll,ll>mp,ans,num; 
ll n,m;
ll a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]=i;
		num[a[i]]++;
	}	
	for(int i=1;i<=m;i++){
		ll j=mp[i];
		ans[i]+=num[i];
		while(j<=n){
			if(mp[a[j]]!=j) j=mp[a[j]];
			else ans[a[++j]]+=num[i];
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
