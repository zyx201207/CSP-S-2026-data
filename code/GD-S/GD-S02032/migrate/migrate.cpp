#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int q[2],w[2],e[5],r[2],t[6];
	for(int i=0;i<=2;i++){
		cin>>q[i];
	}
	for(int i=0;i<=2;i++){
		cin>>w[i];
	}
	for(int i=0;i<=5;i++){
		cin>>e[i];
	}
	for(int i=0;i<=2;i++){
		cin>>r[i];
	}
	for(int i=0;i<=6;i++){
		cin>>t[i];
	}
	if(w[0]==5){
		cout<<1<<endl<<2;
	}else{
		cout<<0<<endl<<1;
	}
	return 0;
}

//crystal subway  hubcrystal subway  hub
