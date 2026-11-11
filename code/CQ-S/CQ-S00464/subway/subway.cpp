#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pint=pair<int,int>;
ll c,n,m,d,q;
ll w[500005];
vector<pint> a[500005];
ll dp[505][505];
void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=(ll)1e14;
		}
		dp[i][i]=0;
	}
} 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin >>w[i];
	} 
	init();
	for(int i=1;i<=n;i++){
		ll k;
		cin >>k;
		for(int j=1;j<=k;j++){
			ll qq,ww;
			cin >>qq>>ww;
			a[qq].push_back({i,ww});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<(int)a[i].size();j++){
			for(int z=0;z<(int)a[i].size();z++){
		        if(j!=z)dp[a[i][j].first][a[i][z].first]=min(dp[a[i][j].first][a[i][z].first],(ll)a[i][j].second+a[i][z].second);		
			}
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=i+1;j<=n;j++){
			for(int z=i;z<=j;z++){
				dp[i][j]=dp[j][i]=min(dp[i][j],dp[i][z]+dp[z][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		ll qq,ww;
		cin >>qq>>ww;
		ll ans=1e14;
		for(int j=0;j<(int)a[qq].size();j++){
			for(int z=0;z<(int)a[ww].size();z++){
				ans=min(ans,dp[a[qq][j].first][a[ww][z].first]+a[qq][j].second+a[ww][z].second);
			}
		}
		cout <<ans+w[qq]+w[ww]<<"\n";
	}
	return 0;
}
