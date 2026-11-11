#include<bits/stdc++.h>
#define int long long
using namespace std;
map<int,int>mp;
int c,n,m,d,q,w[500010],sz[510],dp[510][510],x,y,ns,ans;
vector<pair<int,int> >r[500010];
char cc;
int sum;
int read(){
	while(cc<'0'||cc>'9')cc=getchar();
	sum=0;
	while(cc>='0'&&cc<='9'){
		sum=sum*10+(cc-'0');
		cc=getchar();
	}
	return sum;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		sz[i]=read();
		for(int j=1;j<=sz[i];j++){
			x=read(),y=read();
			r[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1e18;
		}
		dp[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		ns=r[i].size();
		for(int j=0;j<ns;j++){
			for(int k=j+1;k<ns;k++){
				x=r[i][j].first,y=r[i][k].first;
				if(x>y)swap(x,y);
				dp[x][y]=min(dp[x][y],r[i][j].second+r[i][k].second);
				dp[y][x]=dp[x][y];
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=1e18;
		for(auto j:r[x]){
			for(auto k:r[y]){
				ans=min(ans,j.second+k.second+dp[j.first][k.first]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
} 
