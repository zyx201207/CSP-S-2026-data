#include<bits/stdc++.h>
#define int long long
#define fo(i,n) for(int i = 1;i<=n;i++)
#define foi(i,n,m) for(int i = n;i<=m;i++)
using namespace std;
const int N = 1e6 + 10;
int n,m,c,t,dis[N],in[N];
struct node{
	int time,line;
};
vector<node> g[N];
void dij(int u,int fa){
	foi(i,0,g[u].size()-1){
		int v = g[u][i].line;
		int w = g[u][i].time;
		if(v==fa) continue;
		if(dis[v]>dis[u]+w){
			dis[v] = dis[u]+w;
		}
		dij(v,u);
//		cout<<u<<" "<<v<<" "<<dis[v]<<" "<<dis[u]<<" "<<w<<endl;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(in,0,sizeof in);
		memset(dis,0x3f,sizeof dis);
		int n,k;
		cin>>n>>k;
		fo(i,n) g[i].clear();
		fo(i,n-1){
			int x,y;
			cin>>x>>y;
			g[x].push_back((node){1,y}) ;
			g[y].push_back((node){1,x}) ;
			in[x]++;
			in[y]++;
		}
		fo(i,n){
			if(in[i]==1){
				dis[i] = 0;
				dij(i,0);
				break;
			}
		}
		int max1=0,max2=0,max3=0,max4=0;
		fo(i,n){
//			if(in[i]!=1) continue;
//			cout<<dis[i]<<" ";
			foi(j,i+1,n){
				if(in[j]!=1) continue;
				int num = abs(dis[i]-dis[j]) ;
				if(num>=max1){
					max4 = max3;
					max3 = max2;
					max2 = max1;
					max1 = num;
				}
				else if(num>=max2){
					max4 = max3;
					max3 = max2;
					max2 = num;
				}
				else if(num>=max3){
					max4 = max3;
					max3 = num;
				}
				else if(num>=max4){
					max4 = num;
				}
			}
		}
//		cout<<max1<<" "<<max2<<" "<<max3<<" ";
		cout<<max4<<endl;
	}
}

