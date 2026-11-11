#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int c,n,m,d,q,w[M],T;
bool book[M];
vector<pair<int ,int> > v[M];
queue<int> qu;
int bfs(int st,int end){
	memset(book,0,sizeof book);
	int ans=0;
	qu.push(st);
	book[st]=1;
	while(!qu.empty()){
		ans++;
		for(auto e:v[qu.front()]){
			if(book[e.first]==0){
				qu.push(e.first);
				book[e.first]=1;
			}
		}
		qu.pop();
		if(book[end]==1) return ans;
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k,x[M],y[M];
		cin>>k;
		memset(x,0,sizeof x);
		memset(y,0,sizeof y);
		for(int j=1;j<=k;j++){
			cin>>x[j]>>y[j];
		}
		for(int j=1;j<=k;j++){
			for(int p=j+1;p<=k;p++){
				int z=y[j]+y[p];
				v[x[j]].push_back({x[p],z});
				v[x[p]].push_back({x[j],z});
				T=z;
			}
		}
	}
	for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+(bfs(x,y)*T)<<"\n";
		}
	
	
	return 0;
}
