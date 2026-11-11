#include<bits/stdc++.h>
using namespace std;
const int M=500005;
int c,n,m,d,q;
int w[M],k[510];
vector<pair<int,int> > mp[M];
int solve(int x,int y){
	queue<pair<int,int> > q;//去 ，值 
	q.push({x,0});
	while(!q.empty()){
		pair<int,int> tmp=q.front();
		if(tmp.first==y) return tmp.second;
		q.pop();
		for(int i=0;i<mp[tmp.first].size();i++){
			q.push({mp[tmp.first][i].first,tmp.second+mp[tmp.first][i].second});
		}
	}
	return -1;
}
int solvee(int x,int y){
	queue<pair<int,int> > q;//去 ，值 
	q.push({x,0});
	while(!q.empty()){
		pair<int,int> tmp=q.front();
		if(tmp.first==y) return tmp.second;
		q.pop();
		for(int i=0;i<mp[tmp.first].size();i++){
			q.push({mp[tmp.first][i].first,tmp.second+mp[tmp.first][i].second});
		}
	}
	return -1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(c>=7&&c<=11){
		int a[5]={},t[5]={};
		for(int i=1;i<=n;i++){
			cin>>k[i];
			if(k[i]==1) continue;
			for(int j=1;j<=k[i];j++){
				cin>>a[j]>>t[j];
			}
			mp[a[1]].push_back({a[2],t[1]+t[2]});
			mp[a[2]].push_back({a[1],t[1]+t[2]});
		}
		int x,y;
		for(int i=1;i<=q;i++){
			cin>>x>>y;
			cout<<solve(x,y)+w[x]+w[y];
		} 
	}
	if(c>=12&&c<=19){
		for(int i=1;i<=n;i++){
			cin>>k[i];
			vector<int> a(k[i]),t(k[i]);
			if(k[i]==1) continue;
			for(int j=1;j<=k[i];j++){
				cin>>a[i]>>t[i];
			}
			for(int x=1;x<=k[i];x++){
				for(int j=1;j<=k[i];j++){
					mp[a[x]].push_back({a[j],t[x]});
					mp[a[j]].push_back({a[x],t[x]});
				}
			}
		}
		int x,y;
		for(int i=1;i<=q;i++){
			cin>>x>>y;
			cout<<solvee(x,y)+w[x]+w[y];
		} 
	}
	return 0;
}

