#include<bits/stdc++.h>
using namespace std;
char n[3][2],m[4][2];
bool b=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>n[i][0];
	}
	for(int i=1;i<=3;i++){
		cin>>m[i][0];
	}
	for(int i=1;i<=2;i++){
		cin>>n[i][1];
	}
	for(int i=1;i<=3;i++){
		cin>>m[i][1];
	}
	if(n[1][0]==n[1][1]&&n[2][0]==n[2][1]){
		cout<<1;
		b=true;
	}else{
		cout<<"0000";
		return 0;
	}
	
	if(m[1][0]==m[1][1]&&m[2][0]==m[2][1]){
		cout<<1;
		b=true;
	}else{
		b=false;
		cout<<"000";
		return 0;
	}
	
	if(b){
		if(m[3][0]<'D'&&m[3][1]<'D') cout<<1;
		else if(m[3][0]>'C'&&m[3][1]>'C') cout<<1;
		else {
			cout<<"00";
			b=false;
			return 0;
	}
	}else{
		cout<<"00";
	}
	int u=m[3][0]-m[3][1];
	if(b&&(u==1||u==-1)){
		cout<<1;
	}else{
		cout<<0;
	}
}
