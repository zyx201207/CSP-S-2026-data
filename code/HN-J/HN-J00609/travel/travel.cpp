#include<bits/stdc++.h>
using namespace std;
int o(int a,int b){
	if(a=='D'&&b=='F') return 1;
	if(a=='F'&&b=='D') return 1;
	if(a=='A'&&b=='B') return 1;
	if(a=='B'&&b=='A') return 1;
	if(a=='A'&&b=='C') return 1;
	if(a=='C'&&b=='A') return 1;
	if(a=='B'&&b=='C') return 1;
	if(a=='C'&&b=='B') return 1;
}
int j(int a,int b){
	if(a=='D'&&b=='F') return 1;
	if(a=='F'&&b=='D') return 1;
	if(a=='A'&&b=='B') return 1;
	if(a=='B'&&b=='A') return 1;
	if(a=='B'&&b=='C') return 1;
	if(a=='C'&&b=='B') return 1;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a;
	cin>>a;
	char x[4];
	for(int i=1;i<=3;i++){
		cin>>x[i];
	} 
	int c;
	cin>>c;
	char y[4];
	for(int i=1;i<=3;i++){
		cin>>y[i];
	}
	if(a==c){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;	
	}
	if(x[1]==y[1]&&x[2]==y[2]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(o(x[3],y[3])==1){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(j(x[3],y[3])==1){
		cout<<1;
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}
