#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int u[1000005],v[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		cout<<u[n-1]-u[n-2]<<'\n';
	}
	return 0;
}
