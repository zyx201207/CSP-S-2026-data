#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,u,v;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++) cin>>u>>v;
		int m=(n-1)/2;
		if(k==n){
			cout<<0<<"\n";
		}
		else if(k%2!=0){
			if(k>=m-1&&k<n){
				cout<<1<<"\n";
			}
			else{
				cout<<m-k<<"\n";
			}
		}
		else{
			if(k>=m&&k<n){
				cout<<1<<"\n";
			}
			else{
				cout<<m-k+1<<"\n";
			}
		}
	}
	return 0;
}

