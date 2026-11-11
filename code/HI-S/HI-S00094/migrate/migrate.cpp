#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int c,t;
int n,d;
ll a[N],cnt[15][15][15],minn;
void dfs(int x,ll len,int u,int v){
	if(x>v) return;
	if(len>minn) return;
	if(x==v){
		cnt[u][v][len]++;
		minn=min(minn,len);
		//cout<<len<<' ';
		return;
	}
	for(int j=x+1; j<=v; j++){
		if(a[j]-a[x]>d) break;
		dfs(j,len+1,u,v);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int j=1; j<=n; j++) cin>>a[j];
		ll ans=0;
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++){
				if(k<j) continue;
				minn=1e18;
				dfs(j,0,j,k);
				if(minn<=n && cnt[j][k][minn]==2) ans++;
			}
		}
		cout<<ans<<"\n";
		memset(cnt,0,sizeof(cnt));
	}
	return 0;
}
