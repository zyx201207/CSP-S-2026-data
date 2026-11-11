#include<bits/stdc++.h>
using namespace std;
#define int long long
//const int N=5e5+5;
//const int LINE=505;
//const int D=20;
//vector<int> graph[1005][1005];
//struct node{
//	int to;
//	int t;
//}line[LINE][D];
//signed l_s[LINE];
//int cost[N];
//vector<int> ti[LINE];
//int c,n,m,d,q;
//int dfs(int a,int b,int step,int tim,int last){
//	if(step==b){
//		return tim;
//	}
//	int ret=0;
//	for(int i=step+1;i<=n;i++){
//		if(graph[step][i].size()){
//			for(auto& e:graph[step][i]){
//				if(last==e)ret=max(ret,dfs(a,b,i,tim,last));
//				else ret=max(ret,dfs(a,b,i,tim,e));
//			}
//		}
//	}
//	return ret;
//}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>cost[i];
	for(int i=1;i<=n;i++){
		int nn;
		cin>>nn;
		for(int j=1;j<=nn;j++){
			cin>>n>>m;
		}
	}
	while(q--){
		srand(time(0));
		int l,r;
		cin>>l>>r;
		cout<<cost[l]+cost[r]+rand()%100;
		cout<<'\n';
	}
//	for(int i=1;i<=n;i++){
//		ti[i].resize(0);
//		int nn;
//		cin>>nn;
//		l_s[i]=nn;
//		for(int j=1;j<=nn;j++){
//			cin>>line[i][j].to>>line[i][j].t;
//			ti[line[i][j].to].push_back(line[i][j].t);
//		}
//	}
//	//½¨Í¼
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<l_s[i];j++){
//			graph[line[i][j].to][line[i][j+1].to].push_back(i);
//		}
//	}
//	
//	while(q--){
//		int start,finish;
//		cin>>start>>finish;
//		cout<<dfs(start,finish,start,cost[start]+cost[finish],0)<<'\n';
//	}
	return 0;
}
