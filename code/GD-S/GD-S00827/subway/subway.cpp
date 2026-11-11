#include<bits/stdc++.h>
using namespace std;
const int N=522,M=1022;
struct node{
	int x,val;
};
struct noded{
	int ce,x,val;
};
int C,n,m,d,q,w[M],kc[N],dis[N][M],ans;
vector <node> kt[N],c[N];
void bfs(int s,int e){
	memset(dis,0x3f3f3f3f,sizeof(dis));
	queue <noded> q;
	for(auto i:c[s]){
		q.push({i.x,s,i.val});
	}
	while(!q.empty()){
		noded t=q.front();q.pop();
		if(dis[t.ce][t.x]<t.val || ans<t.val) continue ;
		if(t.x==e){
			ans=min(ans,t.val+w[s]+w[e]);
			continue ;
		}
//		dis[t.ce][t.x]=t.val;
		for(auto i:c[t.x]){
			if(i.x==t.ce) continue ;
			if(dis[i.x][t.x]>t.val+i.val){
				q.push({i.x,t.x,t.val+i.val});
				dis[i.x][t.x]=t.val+i.val;
			}
		}
		for(auto i:kt[t.ce]){
			if(i.x==t.x) continue ;
			if(dis[t.ce][i.x]>t.val+i.val){
				q.push({t.ce,i.x,t.val+i.val});
				dis[t.ce][i.x]=t.val+i.val;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>q;
	if(C==20 || C==21){
		if(n==1){
			for(int i=1;i<=m;i++) scanf("%d",&w[i]);
			int VAL[N]={0};
			for(int i=1;i<=n;++i){
				scanf("%d",&kc[i]);
				for(int j=1;j<=kc[i];++j){
					int x,val;
					scanf("%d%d",&x,&val);
					VAL[x]=val;
				}
			}
			while(q--){
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%d\n",w[x]+VAL[x]+VAL[y]+w[y]);
			}
		}else{
			for(int i=1;i<=m;i++) scanf("%d",&w[i]);
			int ds[N][N],VAL[N][2],mi=1e9;
			memset(ds,0x3f3f3f3f,sizeof(ds));
			memset(VAL,-1,sizeof(VAL));
			for(int i=1;i<=n;++i){
				scanf("%d",&kc[i]);
				for(int j=1;j<=kc[i];++j){
					int x,val;
					scanf("%d%d",&x,&val);
					VAL[x][i-1]=val;
				}
			}
			for(int i=1;i<=m;i++){
				if(VAL[i][0]>0 && VAL[i][1]>0){
					mi=min(mi,VAL[i][0]+VAL[i][1]);
				}
			}
			for(int i=1;i<=m;i++){
				for(int j=i+1;j<=m;j++){
					if(VAL[i][0]>0 && VAL[j][0]>0){
						ds[j][i]=ds[i][j]=min(ds[i][j],VAL[i][0]+VAL[j][0]);
					}
					if(VAL[i][1]>0 && VAL[j][0]>0){
						ds[j][i]=ds[i][j]=min(ds[i][j],VAL[i][1]+VAL[j][0]+mi);
					}
					if(VAL[i][0]>0 && VAL[j][1]>0){
						ds[j][i]=ds[i][j]=min(ds[i][j],VAL[i][0]+VAL[j][1]+mi);
					}
					if(VAL[i][1]>0 && VAL[j][1]>0){
						ds[j][i]=ds[i][j]=min(ds[i][j],VAL[i][0]+VAL[j][0]);
					}
				}
			}
			while(q--){
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%d\n",ds[x][y]+w[x]+w[y]);
			}
		}
	}else{
		for(int i=1;i<=m;i++) scanf("%d",&w[i]);
		for(int i=1;i<=n;++i){
			scanf("%d",&kc[i]);
			for(int j=1;j<=kc[i];++j){
				int x,val;
				scanf("%d%d",&x,&val);
				kt[i].push_back({x,val});
				c[x].push_back({i,val});
			}
		}
		while(q--){
			ans=1e9;
			int x,y;
			scanf("%d%d",&x,&y);
			bfs(x,y);
			printf("%d\n",ans);
		}
	}
}
