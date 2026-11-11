#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int c,n,m,d,q;
int w[600001] = {0};
int dis[601][601] = {0},k[601] = {0};
vector<pair<int,int> >trans[600001];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i = 1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i = 1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j = 1;j<=k[i];j++){
			int pos,dw;
			scanf("%lld %lld",&pos,&dw);
//			cout<<i<<" "<<pos<<" "<<dw<<endl;
			trans[pos].push_back({i,dw});
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			dis[i][j] = 1e17;
		}
		dis[i][i] = 0;
	}
//	cout<<"initdone1"<<endl;
	for(int i = 1;i<=m;i++){
		for(int j = 0;j<trans[i].size();j++){
			for(int kk = j+1;kk<trans[i].size();kk++){
//				cout<<"initing:"<<i<<" "<<j<<" "<<kk<<endl;
				int u = trans[i][j].first,v = trans[i][kk].first;
//				cout<<"real:"<<u<<" "<<v<<endl;
				dis[u][v] = min(dis[u][v],trans[i][j].second+trans[i][kk].second);
				dis[v][u] = min(dis[v][u],trans[i][j].second+trans[i][kk].second);
			}
		}
	}
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int kk = 1;kk<=n;kk++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				dis[i][j] = min(dis[i][j],dis[i][kk]+dis[kk][j]);
			}
		}
	}
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=n;j++){
//			cout<<dis[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(q--){
		int u,v;
		scanf("%lld %lld",&u,&v);
		int ans = 1e17;
		for(int i = 0;i<trans[u].size();i++){
			for(int j = 0;j<trans[v].size();j++){
				int du = trans[u][i].first,dv = trans[v][j].first;
				ans = min(ans,dis[du][dv]+trans[u][i].second+trans[v][j].second);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	
	return 0;
}
/*
15:37 100+100+0+0
can i WC?
subway7 1.8s benji,youdianxiaocaidanbudongzayouhuale,jiuzheyangxian
*/
