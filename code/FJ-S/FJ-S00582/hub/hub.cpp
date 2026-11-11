#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u[1111111],v[1111111];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		for(int i=1;i<=n;i++){
			if(n-k*i<=0){
				cout<<i<<endl;
			}
			break;
		}
	}
	
	
	return 0;
}
