#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pa;

struct edge {
	int to;
	int dep;
	int w;
	int next;
};

const int MAXM=5e5+5;
int n,m,d,q;
int depth[MAXM];
vector<int> head[MAXM],dis[MAXM];
vector<edge> vec;

struct cmp {
	bool operator()(pa a,pa b) {
		return dis[a.first][a.second]>dis[b.first][b.second];
	}
};

priority_queue<pa,vector<pa>,cmp> que;

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&n,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) {
		int v;
		scanf("%d",&v);
		depth[i]=2;
		for(int j=0;j<=d+1;j++) head[i].push_back(-1);
		
		edge _e={i,1,v,head[i][0]};
		vec.push_back(_e);
		
		_e={i,0,v,head[i][1]};
		vec.push_back(_e);
		
		head[i][0]=vec.size()-2;
		head[i][1]=vec.size()-1;
	}
	//printf("%d\n",vec.size());
	
	for(int i=1;i<=n;i++) {
		int kk;
		scanf("%d",&kk);
		int a0,t0;
		scanf("%d%d",&a0,&t0);
		
		edge _e={a0,depth[a0],t0,head[a0][1]};
		vec.push_back(_e);
		head[a0][1]=vec.size()-1;
		
		_e={a0,1,t0,head[a0][depth[a0]]};
		vec.push_back(_e);
		head[a0][depth[a0]++]=vec.size()-1;
		
		for(int j=1;j<kk;j++) {
			int a,t;
			scanf("%d%d",&a,&t);
			
			edge _e={a,depth[a],0,head[a0][depth[a0]-1]};
			vec.push_back(_e);
			head[a0][depth[a0]-1]=vec.size()-1;
		
			_e={a0,depth[a0]-1,0,head[a][depth[a]]};
			vec.push_back(_e);
			head[a][depth[a]]=vec.size()-1;
			
			a0=a,t0=t;
			
			_e={a0,depth[a0],t0,head[a0][1]};
			vec.push_back(_e);
			head[a0][1]=vec.size()-1;
		
			_e={a0,1,t0,head[a0][depth[a0]]};
			vec.push_back(_e);
			head[a0][depth[a0]++]=vec.size()-1;
		}
		//printf("%d\n",vec.size());
	}
	
	//printf("%d\n",vec.size());
	
	for(int i=1;i<=m;i++) {
		head[i].resize(depth[i]);
		dis[i].resize(depth[i]);
	}
	
	for(int i=1;i<=q;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		
		for(int i=1;i<=m;i++) {
			for(int j=0;j<depth[i];j++) {
				dis[i][j]=0x3f3f3f3f;
			}
		}
		dis[x][0]=0;
		que.push(pa(x,0));
		while(!que.empty()) {
			auto f=que.top();
			que.pop();
			//printf("now: %d,dep: %d\n",f.first,f.second);
			for(int i=head[f.first][f.second];i!=-1;i=vec[i].next) {
				//printf("edge to: %d,dep: %d,w: %d\n",vec[i].to,vec[i].dep,vec[i].w);
				if(dis[f.first][f.second]+vec[i].w<dis[vec[i].to][vec[i].dep]) {
					dis[vec[i].to][vec[i].dep]=dis[f.first][f.second]+vec[i].w;
					que.push(pa(vec[i].to,vec[i].dep));
				}
			}
		}
		printf("%d\n",dis[y][0]);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

