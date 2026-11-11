#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	} 
	int n1,n2;
	char f1,f2;
	if(b[0]=='1'){
		n1+=10;
	}
	if(d[0]=='1'){
		n2+=10;
	}
	n1+=b[1]-'0',n2+=d[1]-'0';
	if(n1==n2){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	f1=b[2],f2=d[2];
	if((f1=='D'||f1=='F')&&(f2=='D'||f2=='F')){
		cout<<"11";
		return 0;
	}
	if((f1=='A'||f1=='B'||f1=='C')&&(f2=='A'||f2=='B'||f2=='C')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(f1-f2)==1){
		cout<<1;
	}
	else{
		cout<<0; 
	}
	return 0;
} 
/*
MaiMai is the best game in the world.I like it beacuse it can bring me happy.I have a lot of friends about this game.They are friendly.I think MaiMai is magic. 
*/
