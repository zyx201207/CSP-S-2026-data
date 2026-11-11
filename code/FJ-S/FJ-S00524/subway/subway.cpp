#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[500001],wj[501][501],k,aa,b;set <pair<long,long>> st;long long jl=0,dfn[501][501],x,y,maxx,maxxx,rlt;bool vis[501]={};
//st.push({i,1});
vector<long long> v[500001];
map<long,long>mp[500001];
void dfs(long long now,long long endd,long long cnt){
	if(now==endd){
		maxx=min(maxx,cnt);
	};
	for(int i=1;i<=n;i++){
		if(wj[now][i]&&vis[i]==0){
			vis[now]=1;
			dfs(i,endd,cnt+wj[now][i]);
			vis[now]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>aa>>b;
			//cout<<aa<<" "<<b<<endl;
				for(auto it:v[aa]){
				//	cout<<aa<<":"<<it<<endl;
					if(wj[i][it]==0||wj[i][it]>=b+mp[aa][it]){
						wj[i][it]=wj[it][i]=b+mp[aa][it];
					}
				}
			v[aa].push_back(i);
			mp[aa][i]=b;
		}
	}
//	for(int i=1;i<=n;i++){
//		st.clear(),jl=1;
//		for(int j=1;j<=n;j++){
//			vis[j]=0;dfn[i][j]=LONG_LONG_MAX;
//		}
//		for(int j=1;j<=n;j++){
//			if(wj[i][j]){
//				st.insert({i,j});
//			}
//		}
//		vis[i]++;
//		dfn[i][i]=0;
//		while(!st.empty()){
//			
//			pair<long long,long long> now=*st.begin();
//			st.erase(*st.begin());
//			int noww=now.first,to=now.second;
//			cout<<noww<<endl<<endl;
//			cout<<dfn[i][noww]<<" ";
//			if(dfn[i][to]>=dfn[i][noww]+wj[noww][to]&&vis[to]==0){
//				dfn[i][to]=dfn[i][noww]+wj[noww][to];
//				for(int j=1;j<=n;j++){
//					if(wj[to][j]&&vis[j]==0){
//						st.insert({to,j});
//					}
//				}
//				vis[to]=1;
//			}
//		}
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<"dfn["<<i<<"]["<<j<<"]="<<dfn[i][j]<<endl; 
//		}
//	}
	for(int i=1;i<=q;i++){ 
		for(int vv=1;vv<=n;vv++){
			vis[vv]=0;	
		}
		maxx=maxxx=LONG_LONG_MAX;
		cin>>x>>y;
		for(auto xx:v[x]){
			for(auto yy:v[y]){
				maxx=LONG_LONG_MAX;
				vis[xx]=1;vis[yy];
				
				dfs(xx,yy,0);
				vis[xx]=0;vis[yy]=0;
				maxx+=a[x]+a[y];maxx+=mp[x][xx]+mp[y][yy];
				maxxx=min(maxxx,maxx);
			}
		}cout<<maxxx<<endl;
		
	}
	return 0;
} 
