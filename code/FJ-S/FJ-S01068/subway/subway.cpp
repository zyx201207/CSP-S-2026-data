#include<bits/stdc++.h>
using namespace std;
const int M=5e5;
int c;//无用
int n;//总路数 
int m;// 地铁站数
int d;//站最多被线路经过数 
int q;//计划数 
int w[M+5];
struct node{
	int v,t;
};
bool vis[M+5];
vector<node> a[M+5];
int ans=0;
void bfs(int x,int y){
	
	memset(vis,0,sizeof(vis));
	queue<int> q;
	vis[x]==1;
	q.push(x);
	while(!q.empty()){
		int now=q.front();
		//cout<<now<<endl;
		q.pop();
	//	if(now==y)return;
		int tt=0;
		vis[now]=1;
		for(auto i:a[now]){
			
			if(!vis[i.v]){
				tt=i.t;
			//	cout<<i.v<<endl;
				q.push(i.v);
				vis[i.v]=1;
				if(i.v==y){
				ans+=tt;return;}
			}
		}
		ans+=tt;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		vector<int> sht;
		vector<int> pri;
		for(int i=1;i<=k;i++){
			int ai,ti;
			cin>>ai>>ti;
			sht.push_back(ai);
			pri.push_back(ti);
		}
		for(int i=0;i<k;i++){
			for(int j=i+1;j<k;j++){
				a[sht[i]].push_back({sht[j],pri[i]+pri[j]});
				a[sht[j]].push_back({sht[i],pri[i]+pri[j]});
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=0;
		bfs(x,y);
	//	cout<<ans<<endl;
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}
