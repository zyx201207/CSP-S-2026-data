#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		int u,v;
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
		}
		cout<<((k-1)/2)+1<<endl;
	}
	return 0;
}


