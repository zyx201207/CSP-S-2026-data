#include<bits/stdc++.h>
using namespace std;
bool tongpai(char a,char b){
	if(a<'D'&&b<'D'){
		return 1;
	}else if(a>'C'&&b>'C'){
		return 1;
	}
	return 0;
} 
int R,X;
string r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>R>>r>>X>>x;
	if(R==X){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	
	if(r[1]==x[1]&&r[0]==x[0]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	
	if(tongpai(r[2],x[2])){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	
	if((r[2]+1==x[2]||r[2]-1==x[2])||(r[2]=='D'&&x[2]=='F')||(r[2]=='F'&&x[2]=='D')){
		cout<<"1";
	}else{
		cout<<"0";
	} 
	return 0;
}
