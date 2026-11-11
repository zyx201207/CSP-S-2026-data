#include<bits/stdc++.h>
using namespace std;
vector<int> v[105];
bool b[105];
bool vis[105];
int czn;
void dfs1(int x){
	b[x]=1;
	for(int i:v[x]){
		if(b[i]==0&&vis[i]==1){
			dfs1(i);
		}
	}
}
void dfs2(int x,int fa,int y){
	if(vis[x]==1){
		czn=min(czn,y);
		return;
	}
	for(int i:v[x]){
		if(i!=fa){
			dfs2(i,x,y+1);
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k,czs=1e9;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(int mask=1;mask<(1<<n);mask++){
			int czm=0;
			for(int i=1;i<=n;i++){
				if(mask&(1<<(i-1))){
					vis[i]=1;
					czm++;
				}else{
					vis[i]=0;
				}
				b[i]=0;
			}
			if(czm!=k){
				continue;
			}
			czm=0;
			for(int i=1;i<=n;i++){
				if(b[i]==0&&vis[i]==1){
					czm++;
					dfs1(i);
				}
			}
			if(czm>2){
				continue;
			}
			czm=0;
			for(int i=1;i<=n;i++){
				if(vis[i]==0){
					czn=1e9;
					dfs2(i,0,0);
					czm=max(czm,czn);
				}
			}
			czs=min(czs,czm);
		}
		cout<<czs<<"\n";
	}
	return 0;
} 
