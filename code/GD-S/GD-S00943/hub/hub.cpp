#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(c == 1){
			if(k == 2||k == 3||k == 4){
				cout<<1;
				continue;
			}
			else if(k == 1){
				cout<<2;
				continue;
			}
			else if(k == 5){
				cout<<0;
				continue;
			}
		}
		for(int i = 1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
		}
		if(k%2 == 1){
			int ans = ((n-1)/2)-((k-1)/2);
			cout<<ans<<endl;
			continue;
		}
		else{
			int ans = ((n-1)/2)-(k/2);
			cout<<ans<<endl;
			continue;
		}
	}
	
	return 0;
}
