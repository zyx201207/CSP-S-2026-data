#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500;
const int M=500000;
vector<int>pte[M];//dian dao zhan
vector<pair<int,int> >e[N];
int c,n,m,d,q,w[M];
int pcost[N][M],ecost[N][N];
void zdl(int st){
	bool book[N];
	memset(book,0,sizeof(book));
	priority_queue<pair<int,int> >pri;
	for(int i=0;i<(int)e[st].size();i++){
		pri.push(e[st][i]);
	}
	ecost[st][st]=0;
	while(pri.size()){
		int u=pri.top().first,w=pri.top().second;
		pri.pop();
		if(book[u])	continue;
		for(int i=0;i<(int)e[u].size();i++){
			int v=e[u][i].first,ww=e[u][i].second;
			if(ecost[st][v]>w+ww){
				ecost[st][v]=w+ww;
				pri.push({v,w+ww});
			}
		}
	}
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(ecost,0x3f3f3f3f,sizeof(ecost));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)	scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int aaa,bbb;
			scanf("%lld%lld",&aaa,&bbb);
			pte[aaa].push_back(i);
			pcost[i][aaa]=bbb;
		}
	}
	for(int k=1;k<=m;k++){
		if(pte[k].size()>=2){//huan cheng zhan
			for(int i=0;i<(int)pte[k].size()-1;i++){
				int u=pte[k][i];
				for(int j=i+1;j<(int)pte[k].size();j++){
					int v=pte[k][j];
					ecost[u][v]=min(ecost[u][v],pcost[u][k]+pcost[v][k]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(ecost[i][j]){
				e[i].push_back({j,ecost[i][j]});
				e[j].push_back({i,ecost[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		zdl(i);
	}
	while(q--){
		int st,ed;
		scanf("%lld%lld",&st,&ed);
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0;i<(int)pte[st].size();i++){
			int u=pte[st][i];
			for(int j=0;j<(int)pte[ed].size();j++){
				int v=pte[ed][j];
				if(u>v)	swap(u,v);
				ans=min(ans,ecost[u][v]+pcost[u][st]+pcost[v][ed]);
			}
		}
		printf("%lld\n",ans+w[st]+w[ed]);
	}
	return 0;
}
//a a a a!
//zui duan lu zen me xie wo wang le a !!!
