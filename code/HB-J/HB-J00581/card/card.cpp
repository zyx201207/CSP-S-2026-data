#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+9;
ll n,m;
ll a[N],t[N],ans[N],book[N];

void dfs(ll s){
	ll len=0;
	for(ll i=s;i<=n;i++){
		bool f=false;
		for(ll j=1;j<=len;j++){
			if(a[i]==t[j]){
				f=true,len=j;
				break;
			}
		}
		if(!f) t[++len]=a[i];
	}
	for(ll i=1;i<=len;i++) ans[t[i]]++;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool A=true;
	for(ll i=1;i<=n;i++){
		 cin>>a[i];
		 if(a[i]<a[i-1]) A=false;
	 }
	if(A){
		for(ll i=1;i<=n;i++) book[a[i]]++;
		for(ll i=1;i<=m;i++) ans[i]+=book[i];
		for(ll i=1;i<=m;i++){
			ans[i]=ans[i]+ans[i-1];
			cout<<ans[i]<<' ';
		}
	}
	else{
		for(ll i=1;i<=n;i++){
			dfs(i);
		}
		for(ll i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	return 0;
	
}
