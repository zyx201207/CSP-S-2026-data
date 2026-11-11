#include<bits/stdc++.h>
#define ll long long 
#define db double
using namespace std;
const int V=1e5+7;
ll n,m,a[V],ans[V];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		ll s[V],cnt=n;
		bool vis[V],worry[V];
		for(int j=1;j<=V;j++) vis[j]=false;
		for(ll j=i+1;j<=n;j++){
			if(!vis[a[j]]&&!worry[a[j]]) s[cnt]=a[j],cnt--;
			else{
				for(int k=1;k<=n;k++){
					if(s[k]==a[j]) s[k]=0,s[k+1]=0,s[n]=s[1+k],worry[a[j]]=false;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i]==i) ans[i]++;
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}
