#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500005];
vector<pair<int,int> >g[500005];
vector<int>a,t;
int dist[405][405];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c<=8)memset(dist,0x3f3f3f3f,sizeof(dist));
	for(int i=1;i<=m;i++)cin>>w[i];
	/*if(c==20||c==21){
		if(n==1){
			
			while(q--){
				int x,y;
				cin>>x>>y;
				if(x==y)cout<<"0\n";
				cout<<dist[x][y]+w[x]+w[y]<<"\n";
			}
		}
	}*/
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		a.push_back(0);
		t.push_back(0);
		for(int j=1;j<=k;j++){
			int aaaa,tttt;
			cin>>aaaa>>tttt;
			a.push_back(aaaa);
			t.push_back(tttt);
		}
		for(int j=1;j<=k;j++){
			for(int v=j+1;v<=k;v++){
				g[a[j]].push_back({t[j]+t[v],a[v]});
				g[a[v]].push_back({t[j]+t[v],a[j]});
				if(c<=8)dist[a[j]][a[v]]=t[j]+t[v],dist[a[v]][a[j]]=t[j]+t[v];
			}
		}
		a.clear();
		t.clear();
	}
	if(c<=8){
		for(int k=1;k<=m;k++){
			for(int i=1;i<=m;i++){
				for(int j=1;j<=m;j++){
					if(dist[i][k]+dist[k][j]<dist[i][j]){
						dist[i][j]=dist[i][k]+dist[k][j];
					}
				}
			}
		}
		while(q--){
			int x,y;
			cin>>x>>y;
			if(x==y)cout<<"0\n";
			cout<<dist[x][y]+w[x]+w[y]<<"\n";
		}
	}
	
	return 0;
	
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
