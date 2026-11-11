#include<bits/stdc++.h>
#define ll long long
using namespace std;
int cas,T,n,k; 
int main(){

	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin>>cas>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
		}
		if(k==n){
			cout<<0<<"\n";
			continue;
		}
		int m=n/2;
		if(k>=m){
			cout<<1<<"\n";
			continue;
		}else{
			cout<<(m-k+3)/4+1<<"\n";
		}
	}

	return 0;
}

