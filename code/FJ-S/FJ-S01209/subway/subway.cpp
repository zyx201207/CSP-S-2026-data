#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ulp(i,a,b) for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define v first
#define w second
const int N=6e5+5,inf=1e18;
int c,n,m,d,q,w[N],k[N],dist[505][505];
#define V(i) (i+n)
vector<pii>e[N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	ulp(i,1,m)cin>>w[i];
	ulp(i,1,n){
		cin>>k[i];
		ulp(j,1,k[i]){
			int a,t;cin>>a>>t;
			e[V(a)].push_back({i,t});
			e[i].push_back({V(a),t});	
		}
	}
	ulp(i,1,n){
		ulp(j,1,n){
			if(i==j)dist[i][j]=0;
			else dist[i][j]=inf;
		}
	}
	ulp(i,1,n){
		for(pii to:e[i]){
			for(pii toto:e[to.v]){
				if(toto.v==i)continue;
				dist[i][toto.v]=dist[toto.v][i]=min(to.w+toto.w,dist[i][toto.v]);
			}
		}
	}
	ulp(k,1,n){
		ulp(i,1,n){
			if(i==k)continue;
			ulp(j,1,n){
				if(i==j||k==j)continue;
				dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}//²»Òª±¬°¡
//	ulp(i,1,n){
//		ulp(j,1,n){
//			cout<<dist[i][j]<<" ";
//		}
//		puts("*");
//	}
	ulp(qq,1,q){
		int start,end;
		cin>>start>>end;
		int ans=inf;
		for(pii tos:e[V(start)]){
			for(pii toe:e[V(end)]){
				//cout<<tos.v<<" "<<toe.v<<" "<<tos.w<<" "<<toe.w<<"**\n";
				ans=min(ans,tos.w+toe.w+dist[tos.v][toe.v]);
			}
		}
		cout<<ans+w[start]+w[end]<<"\n";
	} 
}
