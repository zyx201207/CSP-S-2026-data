#include<bits/stdc++.h>
#include<queue>
typedef long long ll;
const int MAXN=200010;
using namespace std;
ll c,n,m,d,q;
ll w[MAXN],k[1010];
ll nlulu[MAXN][30][3],nth[MAXN];
bool jxt[MAXN];
struct xnzb{
	ll a,t;
} xhz[510][MAXN];
struct xqq{
	ll v,i,t;
};
int x,y;
ll bfs(int st,int en){
	queue<xqq> que;
	ll ans=9999999999;
	for(int i=1;i<=nth[st];i++){
		que.push(xqq{st,nlulu[st][i][1],xhz[nlulu[st][i][1]][nlulu[st][i][1]].t});
	}
	jxt[st]=1;
	while(!que.empty()){
		xqq nnm=que.front();
		que.pop();
//		cout<<nnm.v<<" "<<nnm.t<<endl;
		if(nnm.v==en){
			ll nnmi=0;
			for(int i=1;i<=nth[en];i++){
				if(nnm.i==nlulu[en][i][1]){
					nnmi=i;
				}
			}
			ans=min(ans,nnm.t+xhz[nlulu[en][nnmi][1]][nlulu[en][nnmi][2]].t);
		}
		if(nlulu[nnm.v][nnm.i][2]==1){
			if(!jxt[xhz[nnm.i][2].a]){
				jxt[xhz[nnm.i][2].a]=1;
				que.push(xqq{xhz[nnm.i][2].a,nnm.i,nnm.t});
//				jxt[xhz[nnm.i][2].a]=0;
			}
		}
		else if(nlulu[nnm.v][nnm.i][2]==k[nnm.i]){
			if(!jxt[xhz[nnm.i][k[nnm.i]-1].a]){
				jxt[xhz[nnm.i][k[nnm.i]-1].a]=1;
				que.push(xqq{xhz[nnm.i][k[nnm.i]-1].a,nnm.i,nnm.t});
//				jxt[xhz[nnm.i][k[nnm.i]-1].a]=0;
			}
		}
		else{
			ll nnmi=0;
			for(int i=1;i<=nth[nnm.v];i++){
				if(nnm.i==nlulu[nnm.v][i][1]){
					nnmi=i;
				}
			}
			if(!jxt[ xhz[ nnm.i ][ nlulu[ nnm.v ][ nnm.i ][2]-1 ].a]){
				
				jxt[ xhz[ nnm.i ][ nlulu[ nnm.v ][ nnm.i ][2]-1 ].a]=1;
				que.push(xqq{xhz[ nnm.i ][ nlulu[ nnm.v ][ nnmi ][2]-1 ].a,nnm.i,nnm.t});
//				jxt[ xhz[ nnm.i ][ nlulu[ nnm.v ][ nnm.i ][2]-1 ].a]=0;
			}
			for(int i=1;i<=nth[nnm.v];i++){
				if(nnm.i==nlulu[nnm.v][i][1]){
					nnmi=i;
				}
			}
			if(!jxt[ xhz[ nnm.i ][ nlulu[ nnm.v ][ nnmi ][2]+1 ].a]){
				jxt[ xhz[ nnm.i ][ nlulu[ nnm.v ][ nnmi ][2]+1 ].a]=1;
				que.push(xqq{xhz[ nnm.i ][ nlulu[ nnm.v ][ nnmi ][2]-1 ].a,nnm.i,nnm.t});
//				jxt[ xhz[ nnm.i ][ nlulu[ nnm.v ][ nnmi ][2]+1 ].a]=0;
			}
		}
		for(int i=1;i<=nth[nnm.v];i++){
				if(nlulu[ nnm.v ][ i ][2]!=1){
					if(!jxt[ xhz[ nlulu[ nnm.v ][ i ][1] ][ nlulu[ nnm.v ][ i ][2]-1 ].a]){	
						jxt[ xhz[ nlulu[ nnm.v ][ i ][1] ][ nlulu[ nnm.v ][ i ][2]-1 ].a]=1;
						que.push(xqq{xhz[ nlulu[ nnm.v ][ i ][1] ][ nlulu[ nnm.v ][ i ][2]-1 ].a,i,nnm.t+xhz[nnm.v][nnm.i].t+xhz[ nlulu[ nnm.v ][ i ][1]][ nlulu[ nnm.v ][ i ][2] ].t});
//						jxt[ xhz[ nlulu[ nnm.v ][ i ][1] ][ nlulu[ nnm.v ][ i ][2]-1 ].a]=0;
					}
				}
				if(nlulu[ nnm.v ][ i ][2]!=k[ nlulu[ nnm.v ][ i ][1] ]){
					if(!jxt[ xhz[ nlulu[ nnm.v ][ i ][1] ][ nlulu[ nnm.v ][ i ][2]+1 ].a]){
						jxt[ xhz[ nlulu[ nnm.v ][ i ][1] ][ nlulu[ nnm.v ][ i ][2]+1 ].a ]=1;
						que.push(xqq{xhz[ nlulu[ nnm.v ][ i ][1] ][ nlulu[ nnm.v ][ i ][2]+1 ].a,i,nnm.t+xhz[nnm.v][nnm.i].t+xhz[ nlulu[ nnm.v ][ i ][1]][ nlulu[ nnm.v ][ i ][2] ].t});
//						jxt[ xhz[ nlulu[ nnm.v ][ i ][1] ][ nlulu[ nnm.v ][ i ][2]+1 ].a ]=0;
					}
				}
			
		}
	}
	return ans;
}
int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>xhz[i][j].a>>xhz[i][j].t;
			nlulu[xhz[i][j].a][++nth[xhz[i][j].a]][1]=i;
			nlulu[xhz[i][j].a][nth[xhz[i][j].a]][2]=j;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			jxt[j]=0;
		}
		cout<<bfs(x,y)+w[x]+w[y]<<endl;
	}
	
	return 0;
}
