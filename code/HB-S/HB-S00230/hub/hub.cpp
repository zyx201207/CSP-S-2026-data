#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		int u,v;
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
		}
		cout<<(n-(n+1)/2+5)/4;
	}
	return 0;
}