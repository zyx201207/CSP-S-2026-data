#include<bits/stdc++.h>
using namespace std; 
#define ll long long 
#define MAXN 520
#define MAXM 500005
int c,m,n,d,q; 
ll w[MAXM],k[MAXM]; 
ll edge[MAXN][MAXN],dist[MAXN][MAXN];
vector<ll> edge2[MAXN];
struct node{
	ll num1; 
	ll num2;
};
struct xrtend{
	int s,d;
}edge4[MAXN];
vector<node> edge3[MAXN]; 
void init(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){ 
  		scanf("%lld",&w[i]);
    }
	ll x,y;
	for(int i=1;i<=n;i++){ 
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){ 
			scanf("%lld%lld",&x,&y);
			edge2[i].push_back(x);
			edge3[x].push_back({i,y}); 
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&edge4[i].s,&edge4[i].d); 
	}
	memset(edge,0x3f,sizeof(edge)); 
	memset(dist,0x3f,sizeof(dist)); 
	for(int i=1;i<=n;i++){ 
		edge[i][i]=0; 
	}
}  
void Floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=edge[i][j];
		} 
	}
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		for(int h=1;h<=n;h++){
    			dist[i][j]=min(dist[i][j],dist[i][h]+dist[h][j]);
			}
		}
	} 
} 
void answer(int u,int v){  
	int len1=edge3[u].size(),len2=edge3[v].size();
	ll ans=dist[0][0],sum2,sum1;
	int tot1,tot2;
	int flag=0;
	for(int i=0;i<len1;i++){
		if(flag){
			break;
		}
		tot1=edge3[u][i].num1;
		sum1=edge3[u][i].num2;
		for(int j=0;j<len2;j++){
			tot2=edge3[v][j].num1;
			sum2=edge3[v][j].num2; 
			ans=min(ans,dist[tot1][tot2]+sum1+sum2);
		}
	}
	ans+=w[u];
	ans+=w[v];
	cout<<ans<<"\n";
}
int main(){ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
    init();
	for(int id=1;id<=m;id++){
		if(edge3[id].size()>1){
			int len=edge3[id].size();
			ll tot1,tot2,wt1,wt2;
			for(int i=0;i<len;i++){
			    tot1=edge3[id][i].num1;
			    wt1=edge3[id][i].num2;
				for(int j=i+1;j<len;j++){ 
					tot2=edge3[id][j].num1;
					wt2=edge3[id][j].num2;
					edge[tot1][tot2]=min(edge[tot1][tot2],wt1+wt2);
					edge[tot2][tot1]=min(edge[tot2][tot1],wt1+wt2);
				}
			}
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dist[i][j]=edge[i][j];
		} 
	}
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		for(int h=1;h<=n;h++){
    			dist[i][j]=min(dist[i][j],dist[i][h]+dist[h][j]);
			}
		}
	} 
	for(int i=1;i<=q;i++){
		answer(edge4[i].s,edge4[i].d);
	} 
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5 
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
1 2 
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100 
3 2 6 3 1 7 2 
4 3 2 5 100 4 6 6 7 
1 6 
2 3
*/ 
