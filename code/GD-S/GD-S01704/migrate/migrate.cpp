#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e6+7,INF=0x3f3f3f3f;
ll c,t,n,d,cnt1,cnt2,ans,a[maxn];
bool vis[maxn],x11[maxn],y11[maxn];
void dfs(ll x,ll y,ll step){
	if(x==y){
		cnt1=min(cnt1,step);
		if(cnt1==step){
			for(ll i=1;i<=n;i++){
				x11[i]=vis[i];
			}
		}
		return;
	}
	for(ll i=max(1ll,x-d);i<=min(n,x+d);i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(i,y,step+1);
			vis[i]=false;
		}
	}
}
bool check(){
	for(ll i=1;i<=n;i++){
		if(x11[i]!=y11[i]){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				cnt1=INF;
				dfs(i,j,1);
				cnt2=cnt1;
				cnt1=INF;
				for(ll i=1;i<=n;i++){
					y11[i]=x11[i];
				}
				dfs(j,i,1);
				if(cnt1==cnt2&&check()&&cnt1!=INF){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}