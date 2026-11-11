#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

const int N=505;
const int M=5e5+10;

int c,n,m,d,q;

int w[M],k[N],dis[N][N];

vector<pair<int,int>> o[M];

signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false); cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int i=1;i<=n;i++){
		
		cin>>k[i];
		
		for(int j=1;j<=k[i];j++){
			
			int a,t; cin>>a>>t;
			
			o[a].push_back({i,t});
			
		}
		
	}
	
	memset(dis,0x3f,sizeof(dis));
	
	for(int i=1;i<=n;i++) dis[i][i]=0;
	
	for(int i=1;i<=m;i++){
		
		for(int s1=0;s1<o[i].size();s1++){
			
			for(int s2=0;s2<o[i].size();s2++){
				
				if(s1==s2) continue;
				
				pair<int,int> op1=o[i][s1],op2=o[i][s2];
				
				dis[op1.fi][op2.fi]=min(dis[op1.fi][op2.fi],op1.se+op2.se);
				
			}
			
		}
		
	}
	
	for(int k=1;k<=n;k++){
		
		for(int i=1;i<=n;i++){
			
			for(int j=1;j<=n;j++){
				
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				
			}
			
		}
		
	}
	
	while(q--){
		
		int s,t; cin>>s>>t;
		
		int minn=1e18;
		
		for(int s1=0;s1<o[s].size();s1++){
			
			for(int s2=0;s2<o[t].size();s2++){
				
				minn=min(minn,dis[o[s][s1].fi][o[t][s2].fi]+o[s][s1].se+o[t][s2].se);
				
			}
			
		}
		
		cout<<w[s]+w[t]+minn<<'\n';
		
	}
	
	
}
