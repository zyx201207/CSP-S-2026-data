#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1010101;
ll c,n,t,d,minn,cnt,pos[N];
void dfs(ll x,ll y,ll z){
	if(x==y){
		if(z==minn)cnt++;
		if(z<minn)minn=z,cnt=1;
		return;
	}
	for(int i=x+1;i<=y;i++){
		if(pos[i]-pos[x]<=d){
			dfs(i,y,z+1);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ll ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>pos[i];
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				cnt=0,minn=1e9;
				dfs(i,j,0);
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
