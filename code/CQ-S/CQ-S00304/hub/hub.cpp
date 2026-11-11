#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t;
int mp[10001][10001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			mp[u][v]=i;
			mp[v][u]=i;
		}
		cout<<k<<endl;;
	}
	return 0;
}

