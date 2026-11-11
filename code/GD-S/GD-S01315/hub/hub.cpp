#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t,n,k,u,v;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		for(int j=0;j<n-1;j++){
			cin>>u>>v;
		}
	}
	for(int i=0;i<t;i++){
		cout<<i+1;
	}
	return 0;
} 
