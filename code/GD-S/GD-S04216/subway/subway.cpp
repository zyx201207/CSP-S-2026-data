#include<bits/stdc++.h>
using namespace std;

struct edge{
	int to,next,w;
} edges[2000005];
int head[500005];
int e_idx = 0;
int p_idx = 0;
int c,n,m,d,q;
int ti[500005][505]; //t(i,j) 
vector< vector<int> > ai(500005,vector<int>(0)); //i条线路通过的站 
int api[500005][505]; //i条线路 通过第j站的节点编号 
vector< vector<int> > pr(505,vector<int>(0)); //经过i站台的线路 
vector<int> mul; //有多条线路经过的站台 
int w[500005];

void add(int u,int v,int w){
	edges[e_idx].to = v;
	edges[e_idx].next = head[u];
	edges[e_idx].w = w;
	
	head[u] = e_idx;
	e_idx ++;
}



int main(){
	
//	double st = clock();
	
//	freopen("subway1.in","r",stdin);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
//	cin>>c>>n>>m>>d>>q;
//	
//	for(int i=1;i<=n;i++){
//		head[i] = i;
//	}
//	
//	for(int i=1;i<=m;i++){
//		cin>>w[i];
//	}
//	
//	map<int,bool> tmp;
//	for(int i=1;i<=n;i++){
//		int k;
//		cin>>k;
//		for(int j=0;j<k;j++){
//			int a,t;
//			cin>>a>>t;
//			ti[a][i] = t;
//			ai[i].push_back(a);
//			pr[a].push_back(i);
//			if(pr[a].size() > 1 && tmp.count(a) == 0){
//				tmp[a] = true;
//				mul.push_back(a);
//			}
//			
//			api[i][a] = p_idx;
//			p_idx++;
//			
//			if(j >= 1){
////				add(api[i][ai[i][j-1]],api[i][a]);
////				add(api[i][a],api[i][ai[i][j-1]]);
//			}
//		}
//	}
	
	//建图
//	for(int i=0;i<mul.size();i++){ //mul[i] 站 
//		for(int j=0;j<pr[mul[i]].size();j++){ //线路编号 
//			ai[pr[mul[i]][j]][mul[i]] = p_idx;
//			idx++;
//		}
//	} 


		
//	double et = clock();
//	cerr<<"\n"<<et-st<<"ms";
	
	return 0;
} 
