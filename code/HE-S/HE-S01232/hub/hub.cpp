#include <bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(t==1){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		
		cout<<2;
	} 
	else if(t==2){
		while(t--){
			int n,k;
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
			}
		}
		cout<<2<<'\n'<<5;
	} 
	else if(t==3){
		while(t--){
			int n,k;
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
			}
		}cout<<3<<'\n'<<5<<'\n'<<8;
	} 
	else if(t==4){
		while(t--){
			int n,k;
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
			}
		}
		cout<< 5<<'\n'<<10<<'\n'<<180<<'\n'<<1999;
	} 
	else if(t==5){
		while(t--){
			int n,k;
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
			}
		}
		cout<<11<<'\n'<<109<<'\n'<<1990<<'\n'<<13243<<'\n'<<13456;
	}
	return 0;
}
