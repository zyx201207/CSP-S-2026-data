#include<bits/stdc++.h>
using namespace std;
int c,t;
int mp[10006][10006];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			int u,w;
			cin>>u>>w;
			mp[u][w]=1;
			mp[w][u]=1;
		}
	}
	return 0;
}
