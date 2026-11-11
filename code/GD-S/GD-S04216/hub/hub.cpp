#include<bits/stdc++.h>
using namespace std;

struct Un{
	int f[1000005];
	
	void init(int size){
		for(int i=1;i<=size;i++){
			f[i] = i;
		}
	}
	
	int find(int a){
		if(f[a] != a){
			f[a] = find(f[a]);
		}
		return f[a];
	}
	
	void un(int a,int b){
		int ra = find(a);
		int rb = find(b);
		
		if(ra == rb) return;
		
		f[ra] = rb;
	}
} u;
struct edge{
	int to,next;
}edges[2000005];
int head[1000005];
bool vis[1000005];
int idx;
int ans;
int c,T,n,k;
const int inf = 0x3f3f3f3f;

void add(int u,int v){
	edges[idx].to = v;
	edges[idx].next = head[u];
	
	head[u] = idx;
	idx ++;
}

vector<int> BFS(int s){
	
	queue<int> q;
	vector<bool> vis2(n+1,false);
	vector<int> dis(n+1,inf);
	
	dis[s] = 0;
	q.push(s);
	
	while(1){
		
		if(q.empty()) break;
		
		int p = q.front();
		q.pop();
		
		if(vis2[p]) continue;
		
		vis2[p] = true;
		
		for(int i=head[p];i!=-1;i=edges[i].next){
			int to = edges[i].to;
			if(vis2[to]) continue;
			
			dis[to] = dis[p] + 1;
			q.push(to);
		}
	}
	
//	cout<<s<<" ";
//	for(int i=1;i<=n;i++){
//		cout<<dis[i]<<" ";
//	}
//	cout<<endl;
	return dis;
	
}

bool check_un(){
	u.init(n);
	queue<int> q;
	vector<bool> vis2(n+1,false);
	
	q.push(1);

	while(1){
		
		if(q.empty()) break;
		
		int p = q.front();
		q.pop();
		
		if(vis2[p]) continue;
		
		vis2[p] = true;
		
		for(int i=head[p];i!=-1;i=edges[i].next){
			int to = edges[i].to;
			if(vis2[to]) continue;
			
			if(vis[p] && vis[to]) u.un(p,to);
			q.push(to);
		}
	}
	
	map<int,bool> tmp;
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(!vis[i]) continue;
		int root = u.find(i);
		
		if(tmp.count(root) == 0){
			tmp[root] = true;
			cnt ++;
		}
	}
//	for(int i=1;i<=n;i++){
//		if(!vis[i]) continue;
//		cout<<u.find(i)<<" ";
//	}
//	cout<<endl;
//	cout<<"b"<<cnt<<endl;
	
	if(cnt <= 2) return true;
	else return false;
}

void dfs(int p,int d,vector<int>& choosed){
	if(d >= k){
//		for(int i=0;i<choosed.size();i++){
//			cout<<choosed[i]<<" ";
//		}
//		cout<<"\n";
		if(!check_un()) return;
//		cout<<"Y\n";
		
		int max_disr = -1;
		for(int i=1;i<=n;i++){
			vector<int> dis = BFS(i);
			int min_dis = inf;
			if(vis[i]){
				min_dis = 0;
			}
			else{
				for(int j=0;j<choosed.size();j++){
					if(choosed[j] == i) continue;
					min_dis = min(min_dis,dis[choosed[j]]);
				}
			}
//			cout<<min_dis<<" ";
			max_disr = max(max_disr,min_dis);
		}
		
//		cout<<max_disr<<"\n";
		ans = min(ans,max_disr);
		return;
	}
	if(p > n) return;
	
	//ฒปัก
	vis[p] = false; 
	dfs(p+1,d,choosed);
	//ัก
	vis[p] = true;
	choosed.push_back(p);
	dfs(p+1,d+1,choosed);
	vis[p] = false;
	choosed.pop_back(); 
	
}

int main(){
	
//	double st = clock();
	
//	freopen("hub2.in","r",stdin);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>T;
	
	for(int t=0;t<T;t++){
		cin>>n>>k;
		
		for(int i=1;i<=n;i++){
			head[i] = -1;
			vis[i] = false;
		}
		idx = 0;
		ans = inf;
		
		for(int i=0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
//			cout<<u<<" "<<v<<"\n";
			
			add(u,v);
			add(v,u);
		}
		
		vector<int> tmp;
		dfs(1,0,tmp);
		
		cout<<ans<<endl;
	}
	
//	double et = clock();
//	cerr<<"\n"<<et-st<<"ms";
	
	return 0;
} 
