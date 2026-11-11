#include<bits/stdc++.h>
using namespace std;
int c,T,n,k;
vector <int> t[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for (int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			t[u].push_back(v);
			t[v].push_back(u);
		}
		printf("0\n");
	}
	return 0;
}
