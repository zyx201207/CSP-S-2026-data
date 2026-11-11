#include<bits/stdc++.h>

using namespace std;

const int M=5e5+10,N=510,D=30,Q=1e5+10;
int c,n,m,d,q;
long long w[M];
struct Node{
	int id;
	long long sub_w;
};
vector<Node> tu[M];
long long bfs(int v,int u){
	int used[M]={0};
	queue<Node> p;
	Node a={v,0};
	p.push(a);
	long long ans=LONG_LONG_MAX;
	while(!p.empty()){
		Node f=p.front();
		if(f.id==u){
			ans=f.sub_w;
		}
		int len=tu[f.id].size();
		for(int i=used[f.id];i<len;i++){
			used[f.id]=i+1;
			if(tu[f.id][i].sub_w+f.sub_w>=ans){
				continue;
			}
			Node abc={tu[f.id][i].id,tu[f.id][i].sub_w+f.sub_w};
			p.push(abc);
		}
		p.pop();
	}
	return ans;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a[M];
		long long t[M];
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];	
		}
		for(int j=1;j<=k;j++){
			for(int l=j+1;l<=k;l++){
				Node v2={a[l],t[l]+t[j]};
				Node v3={a[j],t[l]+t[j]};
				tu[a[j]].push_back(v2);
				tu[a[l]].push_back(v3);
			}
			
		}
	}
	while(q--){
		int v,u;
		cin>>v>>u;
		long long ans=w[v]+w[u];
		ans+=bfs(v,u);
		cout<<ans<<endl;
	}
	return 0;
}
