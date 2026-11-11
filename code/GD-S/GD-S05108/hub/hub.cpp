#include<bits/stdc++.h>
using namespace std;
unsigned short c,T;
int n,k,sum=0;
int v[10010][10010],ans=1e9;
set<unsigned int>s;
vector<int>vec;
int dist(int i,int j){
	return v[i][j];
}
int d(int i){
	int d_mn=1e7;
	if(s.count(i))return 0;
	for(auto j:s){
		d_mn=min(dist(i,j),d_mn);
	}
	return d_mn;
}
void dfs(int dep){
	if(dep>n||vec.size()+(n-dep)<k)return;
	if(vec.size()==k){
		s.clear();
		for(int t=0;t<vec.size();t++){
			s.insert(vec[t]);
		}
		sum=0;
		for(int t=1;t<=n;t++){
			if(s.count(t))continue;
			sum=max(sum,d(t));
		}
		ans=min(ans,sum);
		return;
	}
	vec.push_back(dep);
	dfs(dep+1);
	vec.pop_back();
	dfs(dep+1);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		ans=1e9;
		memset(v,0,sizeof(v));
		s.clear();
		cin>>n>>k;
		for(int t=1;t<=n;t++){
			fill(v[t]+1,v[t]+n+1,1e7);
		}
		for(int t=0;t<n-1;t++){
			int u,v1;
			cin>>u>>v1;
			v[u][v1]=1;
			v[v1][u]=1;
		}
		for(int k=1;k<=n;k++){
			for(int t=1;t<=n;t++){
				for(int i=1;i<=n;i++){
					if(t==i){
						v[t][i]=0;
						continue;
					}
					v[t][i]=min(v[t][i],v[t][k]+v[k][i]);
				}
			}
		}
//		for(int t=1;t<=n;t++){
//			for(int i=1;i<=n;i++){
//				cout<<v[t][i]<<" ";
//			}
//			cout<<endl;
//		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
} 
