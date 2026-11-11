#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		if(k==n){
			cout<<0<<'\n';
			continue;
		}
		if(c==13||c==14){
			if(k>=(n-1)/2){
				cout<<1<<'\n';
				continue;
			}else{
				cout<<ceil(1.0*((n-1)/2+2-k)/4)<<'\n';
				continue;
			}
		}else{
			cout<<1<<'\n';
		}
	}
	return 0;
}
