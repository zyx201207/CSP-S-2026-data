#include<bits/stdc++.h>
using namespace std;
int c,t,u,v,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u>>v;
		}
		cout<<n/k<<endl;
	}
	return 0;
} 
