#include<bits/stdc++.h>

using namespace std;
#define maxn 2000006
int cnt[5005][5005],c,t,n,d,a[maxn],dis[maxn];
#define ll long long
ll ans=0;
void dfs(int i,int s,int ds){
	if(ds<dis[i]) {
		dis[i] = ds,cnt[s][i] = 1;
	}else if(ds == dis[i]){
		cnt[s][i]++;
	}
//	cnt[s][i]++;
	
	for(int j=i+1;a[j]-a[i]<=d&&j<=n;j++){
		dfs(j,s,ds+1);
	}
}

signed main(){
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans = 0;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c<=10) {
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++) dis[j] = 99999999;
				dfs(i,i,0);
			}
			for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
//				cerr<<i<<' '<<j<<' '<<cnt[i][j]<<'\n';
				if(cnt[i][j]==2) {ans++;}
				cnt[i][j] = 0;
			}	
			cout<<ans<<'\n';
		}else{
			for(int i=1;i+2<=n;i++)
				ans = ans + (n-i-1);
			cout<<ans;
		}
	}
	
	
	return 0;
}
