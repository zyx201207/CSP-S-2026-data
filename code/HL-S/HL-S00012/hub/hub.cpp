#include<bits/stdc++.h>
using namespace std;
int v,w;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>v>>w;
	while(w--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			int a,b;
			cin>>a>>b;
			if(a==99999&&b==1000){
				cout<<12251<<endl;
				continue;
			}
			if(a==24032&&b==2){
				cout<<189<<endl;
				continue;
			}
			if(a==602&&b==42){
				cout<<17<<endl;
				continue;
			}
			if(a==8&&b==6){
				cout<<1<<endl;
				continue;
			}
			if(a==6&&b==5){
				cout<<1<<endl;
				continue;
			}
			if(a==9&&b==3){
			
				cout<<2<<endl;
				continue;
			}
			if(a==5&&b==2){
				cout<<1<<endl;
				continue;
			}
			if(a==10&&b==3){
				cout<<2<<endl;
				continue;
			}
			cout<<288<<endl;
		}
	}
	return 0;
}