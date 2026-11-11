#include<iostream>
using namespace std;
const int M=500000,N=510;
int n,m,d,T;
int w[M],k[N],dis[N+M],vis[N+M],from[N+M];
//vector<int>a[N],t[N];
void dij(int st){
}
int main(){
	ios::sync_with_stdio[0];
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int J;
    cin>>J>>n>>m>>d>>T;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(int i=1;i<m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].push_back(0),T[i].push_back(0);
		for(int j=1;x,y;j<=k[i];j++){
			cin>>x;a[i].push_back(x);
			cin>>y;t[i].push_back(y);
			g[i+m].push_back({i+m,y});
		}
	}
	for(int i=1;i<=T;i++){
		cin>>x[i]>>y[i];
		ans[j]=min(ans[j],dis);
	}
	dij(i);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<"\n";
	
	}
    return 0;
    
}
