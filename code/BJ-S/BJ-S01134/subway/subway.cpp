#include<bits/stdc++.h>
using namespace std;
struct S{
	int n,t;
};
bool operator <(S x,S y){
	return x.t>y.t;
}
int c,n,m,d,q,w[1000000];
vector<S> g[600000];
int d2[600000]={};
int ts23[600000];
void dij(int x,int y){
	priority_queue<S> dq;
	memset(d2,-1,sizeof d2);
	
	dq.push({x,0});
	while(1){
		S f=dq.top();
		//printf("choose %d %d\n",f.n,f.t);
		
		dq.pop();
		if(d2[f.n]<=f.t&&d2[f.n]>=0)continue;
		d2[f.n]=f.t;
		
		g[x].push_back({f.n,f.t});
		g[f.n].push_back({x,f.t});
		
		if(f.n==y){
			cout<<f.t+w[x]+w[y];
			break;
		}
		
		for(int j=g[f.n].size()-1;j>=0;j--){
			S i=g[f.n][j];
			//printf("list %d %d %d\n",i.n,d2[i.n],i.t+f.t);
			if(d2[i.n]<0){
			dq.push({i.n,i.t+f.t});
		}
		}
		
	}
		
}

int main(){
	freopen("subway3.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%d",&x);
			scanf("%d",&y);
			if(k==1)break;
			g[m+i].push_back(S{x,y});
			g[x].push_back(S{m+i,y});
			if(c==22||c==23){
				ts23[x]+=i;
			}
		}
	}
	int min23=INT_MAX;
	if(c==22||c==23){
		for(int i=1;i<=m;i++){
			if(g[i].size()>1&&g[i][0].n==m+1&&g[i][1].n==m+2){
				min23=min(min23,g[i][0].t+g[i][1].t);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d",&x);
		scanf("%d",&y);
		if(c<=11){
			dij(x,y);cout<<endl;
		}if(c==22||c==23){
			if(ts23[x]==3&&ts23[y]==3){
				cout<<min(g[y][1].n+g[x][1].n,g[y][0].n+g[x][0].n);
			}if(ts23[x]==3&&ts23[y]==2){
				cout<<g[y][1].n+g[x][1].n;
			}if(ts23[x]==3&&ts23[y]==1){
				cout<<g[y][0].n+g[x][0].n;
			}if(ts23[x]==2&&ts23[y]==3){
				cout<<g[y][1].n+g[x][1].n;
			}if(ts23[x]==1&&ts23[y]==3){
				cout<<g[y][0].n+g[x][0].n;
			}if(ts23[x]==1&&ts23[y]==1){
				cout<<g[y][0].n+g[x][0].n;
			}if(ts23[x]==2&&ts23[y]==2){
				cout<<g[y][1].n+g[x][1].n;
			}else{
				cout<<g[x][0].n+g[y][0].n+min23;
			}
			cout<<endl;
		}
	}
}
	