#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string s;
const ll N=2e5+10;
struct fm{
	ll l,r,v;
};
ll n,m;
ll a[N];
ll vis[N]={0};
fm aa[N]; 
ll bz=0;
ll gs[N];
bool cmd(fm a,fm b){
	if(a.l==b.l){
		return a.r>b.r;
	}
	return a.l<b.l;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(vis[a[i]]==0){
			vis[a[i]]=i;
		}
		else{
			if(vis[a[i]]){
				bz++;
				aa[bz].l=vis[a[i]];
				aa[bz].r=i;
				aa[bz].v=a[i];
				vis[a[i]]=i;
			}
		}
	}
	sort(aa+1,aa+bz+1,cmd);
	for(ll i=1;i<=n;i++){
		ll vis1[N]={0};
		for(ll j=i;j<=n;j++){
			for(ll k=1;k<=bz;k++){
				if(aa[k].l==j){
					j=aa[k].r+1;
					vis1[aa[k].v]=1;
				}
			}
			vis1[a[j]]=1;
				
		}
		for(ll j=1;j<=m;j++){
			if(vis1[j])gs[j]++;
		}
	}
	for(ll i=1;i<=m;i++){
		cout<<gs[i]<<" ";
	}
	return 0;
}
