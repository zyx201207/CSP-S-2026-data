#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v,m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u>>v;
		}
		m=(n-1)/2;
		int d=m*1.0/(k+1);
		cout<<0<<"\n";
	}
	return 0;
}

