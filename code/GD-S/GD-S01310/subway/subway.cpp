#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, dist,r;
int a[500005];
vector<pair<int,int> > e[1000005];
int v[500005];
int d[500005];
signed main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	
	cin >> c>>n >>m >>dist>>r ;
	for(int i=1;i<=m;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int u,v;
			cin >> u>>v;
			e[m+k].push_back({u,v});
			e[u].push_back({m+k,v});
		}
	}
	while(r--){
		for(int i=1;i<=n;i++){
			d[i]=1e18;
			v[i]=0;
		}
		int x,y;
		cin>> x>>y;
		d[x]=0;
		priority_queue<pair<int, int > ,vector< pair<int, int > > , greater< pair<int, int > > > q;
		q.push({d[x],x});
		while(!q.empty()){
			int p=q.top().second;
			int w=q.top().first;
			q.pop();
			if(v[p]==1){
				continue;
			}
			else{
				v[p]=1;
			}
			for(int i=1;i<=e[p].size();i++){
				//cout<< p<<" "<<i<<" "<<d[p]+w<<" "<<endl;
				if(d[e[p][i].first]>=d[p]+w){
					d[e[p][i].first]=d[p]+w;
					q.push({d[e[p][i].first],i});
				}
			}
		}
		cout << d[y]+a[x]+a[y]<<endl;
	}
	return 0;
}


//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
