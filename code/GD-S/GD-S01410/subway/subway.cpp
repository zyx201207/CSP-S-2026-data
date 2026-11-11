#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=300,M=300,INF=103;
int c,n,m,d,q,sum;
long long ans=1e18;
struct node{
	int v,t;
};
int w[M];
int k[M],a[N][M],t[N][M];
int cnt[N];
int dis[N];
bool vis[N],rb[N][N];
vector<node> e[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	sum=m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			cnt[a[i][j]]++;
			if(cnt[a[i][j]]>1){
				rb[i][j]=1;
				int dian=a[i][j];
				sum++; 
				a[i][j]=sum;
				e[dian].push_back({a[i][j],t[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(rb[i][j]) continue;
			e[a[i][j]].push_back({a[i][j+1],t[i][j+1]});
		}
	}
	//ÊäÈë 
	while(q--){
		int st,sz;
		cin>>st>>sz;
		ans=1e18;
		
	}
	return 0;
}
