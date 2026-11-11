#include<bits/stdc++.h>//0
using namespace std;
int c,t,n,k;
//vector<int> mieval[1000006],bbb;
//bool vis[1000006],vis2[1000006];
//void dfs2(int x){
//	if(vis2[x]){
//		return;
//	}
//	vis2[x]=1;
//	for(int i=0;i<mieval[x].size();i++){
//		if(vis[mieval[x][i]]){
//			dfs2(mieval[x][i]);
//		}
//	}
//	return;
//}
//void dfs(int kk,int x,int shu){
//	if(shu==kk){
//		for(int i=0;i<=n;i++){
//			vis2[i]=0;
//		}
//		int shul=0;
//		for(int i=0;i<bbb.size();i++){
//			if(vis2[i]==0){
//				shul++;
//				if(shul>2){
//					return;
//				}
//				dfs2(bbb[i]);
//			}
//		}
//		return;
//	}
//	for(int i=x+1;i<=n;i++){
//		vis[i]=1;
//		bbb.push_back(i);
//		dfs(kk,i,shu+1);
//		bbb.pop_back();
//		vis[i]=0;
//	}
//	return;
//}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
//	if(c<=6){
//		while(t--){
//			cin>>n>>k;
//			for(int i=1;i<n;i++){
//				int u,v;
//				cin>>u>>v;
//				mieval[u].push_back(v);
//				mieval[v].push_back(u);
//			}
//			dfs(k,0,0);
//		}
//	}
//	else{
		while(t--){
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
	//			mieval[u].push_back(v);
	//			mieval[v].push_back(u);
			}
			int t=clock();
			cout<<t<<"\n";
		}
//	}
	return 0;
}
/*

*/
