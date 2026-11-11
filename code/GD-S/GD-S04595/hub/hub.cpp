#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int c,T,k,n;
vector<int> e[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i = 1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
	}
}
