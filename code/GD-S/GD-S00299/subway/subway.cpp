#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,vis[500005];
map<int,int>a;
map<int,map<int,int>> mp;
queue<int> que;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.ans","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int k=0;k<n;k++){
		int zs;
		cin>>zs;
		map<int,int> tmp;
		for(int i=1;i<=zs;i++){
			int a,time;
			cin>>a>>time;
			tmp[a] = time;
		}
		for(auto i:tmp){
			for(auto j:tmp){
				if(i.first==j.first) continue;
				mp[i.first][j.first] = i.second+j.second;
				//cout<<i.first<<" "<<j.first<<" "<<i.second+j.second<<endl;
			}
		}
	}
	for(int i=0;i<q;i++){
		int st,en;
		cin>>st>>en;
		int ans = a[st]+a[en];
		while(!que.empty()){
			que.pop();
		}
		memset(vis,-1,sizeof vis);
		que.push(st);
		vis[st] = 0;
		while(!que.empty()){
			int l = que.front();
			que.pop();
			//cout<<l<<endl;
			for(auto i:mp[l]){
				if(vis[i.first] == -1||vis[i.first]>vis[l]+i.second){
					//cout<<i.first<<" "<<i.second<<" "<<vis[l]<<endl;
					que.push(i.first);
					vis[i.first] = vis[l]+i.second;
				}
			}
		}
		cout<<ans+vis[en]<<endl;
	}
	return 0;
}
