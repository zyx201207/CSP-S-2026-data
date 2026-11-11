#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		vector<int> ve[10005];
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			ve[u].push_back(v);
			ve[v].push_back(u);
		}
		cout<<n*k;
	}
	return 0;
}
