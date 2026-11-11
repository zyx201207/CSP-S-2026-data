#include<bits/stdc++.h>
using namespace std;
int n,c,t,k;
int d[10005],vis[10005];
vector<vector<int>>g;
int dis(int x){int maxl=1;
	for(int&i:g[x]){
		if(vis[i]){vis[i]=0;
			maxl=max(maxl,dis(i));
		}
	}
	return maxl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		g.assign(n+1,{});
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x); 
		}
		if(k<=2){
			for(int i=1;i<=n;i++){
				for(int i=1;i<=n;i++){
					vis[i]=1;
				}d[i]=dis(i);
			}
			int fi=0,se=0,th=0;
			for(int i=1;i<=n;i++){
				if(fi<d[i])swap(fi,d[i]);
				if(se<d[i])swap(se,d[i]);
				if(th<d[i])swap(th,d[i]);
			}
			cout<<th<<"\n";
			continue;
		}
		cout<<"0\n";
	}
	return 0;
}
