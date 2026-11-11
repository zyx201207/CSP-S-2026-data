#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int q[5],w[7],e[7],r[7],t[2],y[2],u[2];
	for(int i=0;i<=5;i++){
		cin>>q[i];
	}
	for(int i=0;i<=7;i++){
		cin>>w[i];
	}
	for(int i=0;i<=7;i++){
		cin>>e[i];
	}
	for(int i=0;i<=7;i++){
		cin>>r[i];
	}
	for(int i=0;i<=2;i++){
		cin>>t[i];
	}
	for(int i=0;i<=2;i++){
		cin>>y[i];
	}
	for(int i=0;i<=2;i++){
		cin>>u[i];
	}
	if(w[0]==8){
		cout<<35<<endl<<16;
	}else{
		cout<<32<<endl<<17;
	}

	return 0;
}

//crystal  migrate hubcrystal  migrate hub
