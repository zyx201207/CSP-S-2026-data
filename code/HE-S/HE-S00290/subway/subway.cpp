#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int c,n,m,d,q;
int dis[500010];
int w[500010];
vector<int> a[510],t[510];
vector<int> dy[500010];
void judge(int x,int y){
	for(int i=1;i<=m;i++)dis[i]=inf;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		auto u=q.front();
		q.pop();
		
	}
	cout<<dis[y];
}int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		judge(x,y);
	}return 0;
}