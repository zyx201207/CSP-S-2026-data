#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxm=500003;

int read(){
	int x=0,f=1,ch=getchar();
	if(ch<48||ch>57){
		if(ch==45){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

int C,n,m,D,Q,kou[maxm],siz[503];

vector<pair<int,int> >g[maxm];

ll dp[503][503];

void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	return;
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read(),n=read(),m=read(),D=read(),Q=read();
	for(int i=1;i<=500;i++){
		for(int j=1;j<=500;j++){
			if(i!=j){
				dp[i][j]=1e18;
			}
		}
	}
	for(int i=1;i<=m;i++){
		kou[i]=read();
	}
	for(int i=1;i<=n;i++){
		siz[i]=read();
		for(int j=0;j<siz[i];j++){
			int x=read(),y=read();
			g[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=m;i++){
		for(auto s:g[i]){
			for(auto t:g[i]){
				if(s.first!=t.first){
					dp[s.first][t.first]=min(dp[s.first][t.first],0LL+s.second+t.second);
				}
			}
		}
	}
	floyd();
	while(Q--){
		int u=read(),v=read();
		ll res=1e18;
		for(auto s:g[u]){
			for(auto t:g[v]){
				if(s.first==t.first){
					res=min(res,0LL+s.second+t.second);
				}else{
					res=min(res,dp[s.first][t.first]+s.second+t.second);
				}
			}
		}
		cout<<res+kou[u]+kou[v]<<'\n';
	}
	return 0;
}
