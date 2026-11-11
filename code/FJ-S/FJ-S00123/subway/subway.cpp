#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,n,m,d,q;
ll w[500005];
vector<pair<int,ll> > v[500005];
ll dp[505][505];
ll read(){
	ll sum=0;
	int t=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-'){
			t=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=(sum<<3)+(sum<<1)+ch-'0';
		ch=getchar();
	}
	return sum*t;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	memset(dp,0x3f,sizeof(dp));
	for(int i = 1;i<=m;i++){
		w[i]=read();
	}
	for(int i = 1;i<=n;i++){
		int k=read();
		while(k--){
			int x=read();
			ll t=read();
			v[x].push_back(make_pair(i,t));
		}
		dp[i][i]=0;
	}
	for(int i = 1;i<=m;i++){
		for(int j = 0;j<v[i].size();j++){
			int x=v[i][j].first;
			ll wx=v[i][j].second;
			for(int k = j+1;k<v[i].size();k++){
				int y=v[i][k].first;
				ll wy=v[i][k].second;
				dp[x][y]=min(dp[x][y],wx+wy);
				dp[y][x]=dp[x][y];
			}
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			for(int k = 1;k<=n;k++){
				dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]); 
			}
		}
	}
	
	while(q--){
		int x=read();
		int y=read();
		ll ans=0x3f3f3f3f3f3f3f3f;
		for(int i = 0;i<v[x].size();i++){
			for(int j = 0;j<v[y].size();j++){
				ans=min(ans,dp[v[x][i].first][v[y][j].first]+w[x]+w[y]+v[x][i].second+v[y][j].second);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
