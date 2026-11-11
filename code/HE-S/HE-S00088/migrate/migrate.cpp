#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,k,f[110][110][110][2],sz[N];
vector<int>g[N];

int main(){
	ios::sync_with_stdio[0];
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--){
    	cin>>n>>k;
    	for(int i=1;i<=n;i++) g[i].clear(),sz[i]=0;
    	for(int i=1,u,v;i<n;i++){
    		cin>>u>>v;
    		g[u].push_back(v);
    		g[v].push_back(u);
		}
		
	}
    return 0;
}
