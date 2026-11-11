#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int nmax=5005;
ll n,lim;
ll a[nmax];
ll dist[nmax][nmax];
ll ways[nmax][nmax];
void dfs(int pos,int l,int r,int steps){
	if(pos>r) return;
	if(pos==r){
		if(steps==dist[l][r]){
			ways[l][r]++;
		}
		return;
	}
	ll sum=0;
	for(int nxt=pos+1;nxt<=r;nxt++){
		sum+=a[nxt]-a[nxt-1];
		if(sum<=lim){
			dfs(nxt,l,r,steps+1);
		}
		else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int type,t;
	cin>>type>>t;
	while(t--){
		cin>>n>>lim;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=50){
			memset(dist,0,sizeof(dist));
			memset(ways,0,sizeof(ways));
			for(int i=1;i<=n;i++){
				ll sum=0;
				dist[i][i]=1;
				for(int j=i+1;j<=n;j++){
					sum+=a[j]-a[j-1];
					if(sum>lim){
						dist[i][j]=dist[i][j-1]+1;
						sum=0;
					}
					else{
						dist[i][j]=dist[i][j-1];
					}
				//	cout<<i<<" "<<j<<" "<<dist[i][j]<<"$\n";
				}
			}
			for(int l=1;l<=n;l++){
				for(int r=l+2;r<=n;r++){
					dfs(l,l,r,0);
				}
			}
			ll ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(ways[i][j]==2){
						ans++;
					}
				} 
			}
			cout<<ans<<"\n";
		}
		else cout<<0<<"\n";
	}
	return 0;
}
