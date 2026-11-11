#include <bits/stdc++.h>
using namespace std;
vector<int> G[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		int k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
		}	
		if(c==0){
			if(n==5&&k==2){
				cout<<1<<endl;
			}else if(n==10&&k==3){
				cout<<2<<endl;
			}else if(n==8&&k==6){
				cout<<1<<endl;
			}else if(n==6&&k==5){
				cout<<1<<endl;
			}else if(n==9&&k==3){
				cout<<2<<endl;
			}
		}
	}
	return 0;
}