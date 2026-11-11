//GZ-J00075,彭翊瑄，北师大贵阳附中 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vl vector<ll>
#define pll pair<ll,ll>
#define fi first
#define se second
void ji(){
	ll n,m;
	cin>>n>>m;
	vl ans(m+1);
	vl vis(m+1),pos(m+1),a(n+1);
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++)vis[j]=0;
		for(ll j=i;j<=n;j++){
			if(!vis[a[j]]){
				vis[a[j]]=1;
				pos[a[j]]=j;
			}
			else{
				for(ll k=pos[a[j]]+1;k<j;k++){
					vis[a[k]]=0;
					pos[a[j]]=j;
				}
			}
		}
		for(ll j=1;j<=m;j++){
			if(vis[j]){
				ans[j]++;
			}
		}
	} 
	for(ll i=1;i<=m;i++)cout<<ans[i]<<' ';
} 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll t=1;//cin>>t;
	while(t--){
		ji();
	} 
	return 0;
} 
