#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k;
		cin>>n>>k;
		int u,v;
		for(int j=1;j<=n-1;j++){
			cin>>u>>v;
		}
		cout<<k-1;
	}
}
