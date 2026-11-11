#include<bits/stdc++.h>
using namespace std;
int n,k;
int w[100005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v>>w[i];
		}
		sort(w+1,w+n);
		cout<<w[k]<<"\n";
	}
	
	return 0;
}
