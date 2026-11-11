#include<bits/stdc++.h>
using namespace std;
#define int long long
#define filename "subway"
int c,n,m,d,q;
int dtk[505];
int a[505][50005];
int link[50005][505];
int check(int x,int y){
	for(int e:link[x]){
		for(int f:link[y]){
			if(e==f){
				return e;
			}
		}
	}
	return 0;
}
int trans(int x,int y){
	int newline,tran;
	bool f=false;
	for(int line:link[x]){
		for(auto [u,v]:adj[line]){
			for(int linee:link[u]){
				for(auto [ui,vi]:adj[linee]){
					if(ui==y){
						f=true;
						tran=u;
						return pair<line,linee>;
					}
					tran=ui;
				}
			}
			
		}
	}
	if(!f) trans(tran,y);
}
signed main(){
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	vector<pair<int,int>>adj(n+2);
	vector<int>link(m+2);
	for(int i=1;i<=m;i++){
		cin>>dtk[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int dt,dis;
			cin>>dt>>dis;
			link[dt].push_back(i); 
			adj[i].push_back({dt,dis});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
//		int sum=dtk[x]+dtk[y];
		int ans=0;
		int s=check(x,y);
		if(!s){
			for(auto [u,v]:adj[s]){
				if(u==x){
					ans+=v;
				}
				if(u==y){
					ans+=v;
				}
			}
		}else{
			pair<int,int> zho=trans(x,y);
			int fi=zho.first();
			int se=zho.second();
			for(auto [j,n]:adj[fi]){
				for(auto [k,m]:adj[se]){
					if(j==k){
						ans=ans+n+m;
					}
				}
			}
			
		}
		
	}
	
	
	
	
}
