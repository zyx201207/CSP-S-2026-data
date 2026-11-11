#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100;
int w[N];
int k[550],a[550][550],t[550][550],l[550][550];
bool v[550][550];
int c,n,m,d,q;
int dij(int x,int aim){
	priority_queue<pair<int,int> > qu;
	vector<int> dist(m+5,1e9);
	vector<bool> vis(m+5,0);
	dist[x]=0;vis[x]=1;
	pair<int,int> p;
	p.first=dist[x];p.second=x;
	qu.push(p);
	int sum=0;
	while(!qu.empty()){
		pair<int,int> ka=qu.top();
		qu.pop();
		int wo=ka.first,z=ka.second;
		vis[z]=1;
		sum++;
		for(int i=1;i<=m;i++){
			if(v[z][i]==1&&!vis[i]&&dist[i]>wo+l[z][i]){
				dist[i]=wo+l[z][i];
				ka.first=dist[i];ka.second=i;
				qu.push(ka);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		cout<<dist[i]<<" ";
//	}
//	cout<<endl;
	return dist[aim];
	
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	memset(l,0x3f,sizeof(l));
	for(int i=1;i<=m;i++) l[i][i]=0;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			for(int s=i+1;s<=k[i];s++){
				l[a[i][j]][a[i][s]]=min(l[a[i][j]][a[i][s]],t[i][j]+t[i][s]);
				l[a[i][s]][a[i][j]]=min(l[a[i][s]][a[i][j]],t[i][j]+t[i][s]);
				v[a[i][j]][a[i][s]]=v[a[i][s]][a[i][j]]=1;
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			if(l[i][j]>0x3f) cout<<-1<<" ";
//			else cout<<l[i][j]<<" ";
//		}
//		cout<<endl;
//	}


//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<v[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	while(q--){
		int x,y;
	  	cin>>x>>y;
		int ans=dij(x,y)+w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
