//GZ-J00202 郭盛权 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
string rc,rz,xc,xz;
bool isSSide(char c,char x){
	if(c=='A'){
		if(x=='B'||x=='C') return true;
		else return false;
	}
	if(c=='B'){
		if(x=='A'||x=='C') return true;
		else return false;
	}
	if(c=='C'){
		if(x=='A'||x=='B') return true;
		else return false;
	}
	if(c=='D'){
		if(x=='F') return true;
		else return false;
	}
	else{
		if(x=='D') return true;
		else return false;
	}
}
bool isSBSide(char c,char x){
	if(c=='A'){
		if(x=='B') return true;
		else return false;
	}
	if(c=='B'){
		if(x=='A'||x=='C') return true;
		else return false;
	}
	if(c=='C'){
		if(x=='B') return true;
		else return false;
	}
	if(c=='D'){
		if(x=='F') return true;
		else return false;
	}
	else{
		if(x=='D') return true;
		else return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>rc>>rz>>xc>>xz;
	
	if(rc==xc) cout<<1;
	else{
		cout<<"0000"<<endl;
		return 0;
	}
	int rh=(rz[0]-'0')*10+(rz[1]-'0');
	int xh=(xz[0]-'0')*10+(xz[1]-'0');
	if(rh==xh) cout<<1;
	else{
		cout<<"000"<<endl;
		return 0;	
	}
	
	if(isSSide(rz[2],xz[2])) cout<<1;
	else{
		cout<<"00"<<endl;
		return 0;
	}
	if(isSBSide(rz[2],xz[2])) cout<<1;
	else cout<<0<<endl;
	
	return 0;
}
