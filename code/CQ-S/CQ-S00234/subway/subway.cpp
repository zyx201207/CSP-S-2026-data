//15:47 AC subway
/*
	试图拿到S1=
	luogu uid:1612389
	14：59
	AC crystal
	由是宰我
	15：47
	AC subway
	请输入文本
	Junior 348pts（J1=
	Senior 224pts（S2=/S1=
	感觉要S1=力(喜)
	嗯
	万一都做出subway了呢
	那就是一个悲伤的故事了
	感觉今年S和2022差不多
	22年T2:6个ST表
	今年T2：Floyd
	感觉：黄 绿+ 蓝- 紫+ 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int v,w;
};
vector<edge>g[520000];
int c,n,d,q,m,w[502000],dp[1145][1145],a[500050];
//floyd
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k,t;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t;
			g[a[j]].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int p=j+1;p<g[i].size();p++){
				dp[g[i][j].v][g[i][p].v]=min(dp[g[i][j].v][g[i][p].v],g[i][j].w+g[i][p].w);
				dp[g[i][p].v][g[i][j].v]=min(dp[g[i][p].v][g[i][j].v],g[i][j].w+g[i][p].w);
			}
		}
	}
	for(int p=1;p<=n;p++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][p]+dp[p][j]);
			}
		}
	}
	for(int i=1;i<=n;i++)dp[i][i]=0;
	while(q--){
		int s,t;
		cin>>s>>t;
		int ans=11451419198100000ll;
		for(int i=0;i<g[s].size();i++){//from
			for(int j=0;j<g[t].size();j++){//to
				if(g[s][i].w+dp[g[s][i].v][g[t][j].v]+g[t][j].w<ans)
					ans=g[s][i].w+dp[g[s][i].v][g[t][j].v]+g[t][j].w;
			}
		}
		cout<<ans+w[s]+w[t]<<"\n";
	}
	return 0;
}
/*
	CCFCCFCCFCCFCCFCCF		CCFCCFCCFCCFCCFCCF		CCFCCFCCFCCFCCFCCF		
	CCF						CCF						CCF	
	CCF						CCF						CCF
	CCF						CCF						CCF
	CCF						CCF						CCF
	CCF						CCF						CCF
	CCF						CCF						CCFCCFCCFCCFCCFCCF
	CCF						CCF						CCF
	CCF						CCF						CCF
	CCF						CCF						CCF
	CCF						CCF						CCF
	CCF						CCF						CCF
	CCF						CCF						CCF
	CCFCCFCCFCCFCCFCCF		CCFCCFCCFCCFCCFCCF		CCF
	
	
	
	
	      CCFCCFCCF			CCFCCFCCFCCFCCFCCF
	         CCF			CCF
	         CCF			CCF
	         CCF			CCF
	         CCF			CCF
	         CCF			CCFCCFCCFCCFCCFCCF
			 CCF						   CCF
			 CCF						   CCF
			 CCF						   CCF
		  CCFCCFCCF			CCFCCFCCFCCFCCFCCF
		  
	CCFCCFCCFCCFCCF	  		CCFCCFCCFCCFCCFCCF		CCFCCFCCFCCFCCFCCF        CCFCCFCCFCCFCCF
	CCF			CCF			CCF						CCF								CCF
	CCF			CCF			CCF						CCF								CCF
	CCF	  		CCF			CCF						CCF								CCF
	CCF	  		CCF			CCF						CCF								CCF
	CCF	  		CCF			CCF						CCF								CCF
	CCFCCFCCFCCFCCFCCF		CCFCCFCCFCCFCCFCCF		CCFCCFCCFCCFCCFCCF				CCF
	CCF	  		   CCF		CCF									   CCF				CCF
	CCF	  		   CCF		CCF									   CCF				CCF
	CCF	  		   CCF		CCF									   CCF				CCF
	CCF	  		   CCF		CCF									   CCF				CCF
	CCF	  		   CCF		CCF									   CCF				CCF
	CCFCCFCCFCCFCCFCCF	  	CCFCCFCCFCCFCCFCCF		CCFCCFCCFCCFCCFCCF				CCF
	
*/
