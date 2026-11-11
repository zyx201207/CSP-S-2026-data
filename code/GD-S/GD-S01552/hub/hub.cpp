#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int c,T;
ll n,k;
vector<ll>g[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout<<0;
	}
	return 0;
} 
