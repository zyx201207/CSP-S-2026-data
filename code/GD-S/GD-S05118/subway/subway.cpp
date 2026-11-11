#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int c,n,m,d,q;
//n->地铁线路数                       地铁线路编号1->n
//m->地铁站数                         地铁站编号  1->m
//d->每个地铁站最多被 d 条线路经过
//q->出行计划数                        出行计划数 1->q 

int x,y;//起点||终点 

struct Way{
	int v;//地铁线路编号 
	int t;//站厅->站台  时间 
};

struct Node{
	vector<Way> way;
	int num;//从属的地铁线路的数量 
	bool isH;//是否为换乘站
	int w;//地铁口->站厅 时间 
};

vector<Node> sub(1e5+1);
vector<int> ways[501];//地铁线路 
vector<int> wayS[501];//每条线路上的换乘点 
vector<int> wayLen;//地铁线路长度 
vector<int> yt(501,0);
bool arr[500001];

//bool comp(Way a,Way b){
//	return a.v<b.v || (a.v==b.v && a.t<b.t);
//}

long long dfs(int numz,int numl){
	if(numz==y){
		return yt[numl];
	}
	
	arr[numz]=true;
	
	long long out;
	for(Way a : sub[numz].way){
		if(a.v==numl){
			out=a.t;
			break;
		}
	}
	
	long long ans=0;
	for(Way a : sub[numz].way){
		if(a.v==numl){
			continue;
		}
		
		int len=wayS[a.v].size();
		for(int i=0;i<len;i++){
			if(wayS[a.v][i]==numz){
				continue;
			}
			
			long long add=0;
			if(ans==0){
				ans=dfs(wayS[a.v][i],a.v)+a.t+out;
			}else{
				ans=min(ans,dfs(wayS[a.v][i],a.v)+a.t+out);
			}
		}
	}
	
	if(yt[numl]!=0){
		ans=dfs(y,numl);
	}
	
	arr[numz]=false;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		int a;
		cin>>a;
		
		sub[i].w=a;
		sub[i].num=0;
		sub[i].isH=false;
	}
	
	wayLen.push_back(0);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		wayLen.push_back(k);
		
		ways[i].push_back(0);
		for(int j=1;j<=k;j++){
			int a,t;//编号||时间 
			cin>>a>>t;
			
			ways[i].push_back(a);
			sub[a].way.push_back({i,t});
			sub[a].num++;
		}
	}
	
	for(int i=1;i<=m;i++){
		if(sub[i].num>=2){
			sub[i].isH=true;
			for(int j=0;j<sub[i].num;j++){
				wayS[sub[i].way[j].v].push_back(i);
			}
//			sort(sub[i].way.begin(),sub[i].way.end(),comp);
		}
	} 
	
	for(int i=0;i<q;i++){
		int x;//起点编号 
		int y;//终点编号 
		cin>>x>>y;
		
		long long ans=sub[x].w+sub[y].w;
		
		for(int j=0;j<sub[y].num;j++){
			yt[sub[y].way[j].v]=sub[y].way[j].t;
		}
		
		long long add;
		for(int j=0;j<sub[x].num;j++){
			if(j==0){
				add=dfs(x,sub[x].way[j].v)+sub[x].way[j].t;
			}else{
				add=min(add,dfs(x,sub[x].way[j].v)+sub[x].way[j].t);
			}
		}
		
		for(int j=0;j<sub[y].num;j++){
			yt[sub[y].way[j].v]=0;
		}
		
		ans+=add;
		
		cout<<ans<<endl;
	}
	return 0;
} 
