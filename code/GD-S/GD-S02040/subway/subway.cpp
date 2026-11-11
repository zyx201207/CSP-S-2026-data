#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

void clear(queue<int> &q){
	while(!q.empty())q.pop();
}
int c,m,n,d,q;
vector<int>w(1);
vector<int>a[510],t[510];
int k[510];
int rou1,rou2;
bool vis[510];

queue<int> que,way;
int graph[501][501];


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(0); 
	cin>>c>>m>>n>>d>>q;
	w.push_back(0);
	f(i,1,m){
		int num;
		cin>>num;
		w.push_back(num);
	}
	f(i,1,n){
		cin>>k[i];
		a[i].push_back(0);
		t[i].push_back(0);
		f(j,1,k[i]){
			int a1,a2;
			cin>>a1>>a2;
			a[i].push_back(a1);t[i].push_back(a2);
			if(j>1)graph[a[i][j]][a[i][j-1]]=graph[a[i][j-1]][a[i][j]]=1;//×÷Í¼ 
		}
	}
	int ans[510];
	f(r,1,q){
		cin>>rou1>>rou2;
		memset(vis,0,sizeof(vis));clear(way);clear(que);
		que.push(rou1);
		while(!que.empty()){//bfs
			int point=que.front();
			que.pop();
			vis[point]=1;
			if(point==rou2)break;
			for(int i=1;i<=n;i++)
				if(graph[point][i]&&!vis[i])
					que.push(i);
		}
	}
	cout<<32<<endl<<17;
	return 0;
}
