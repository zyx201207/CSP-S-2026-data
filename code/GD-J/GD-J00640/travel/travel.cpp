#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	int rx,xx;
	string rz,xz;
	bool ok=true,rl,xl;
	cin>>rx>>rz>>xx>>xz;
	int rp=(rz[0]-'0')*10+(rz[1]-'0'),xp=(xz[0]-'0')*10+(xz[1]-'0');
	char rwei=rz[2],xwei=xz[2],t;
	if(rx == xx){
		cout<<"1";
	}
	else{
		ok=0;
		cout<<"0";
	} 
	if(rp == xp&&ok){
		cout<<"1";
	}
	else{
		ok=0;
		cout<<"0";
	}
	if(rwei=='A'||rwei=='B'||rwei=='C'){
		rl=true;
	}
	else{
		rl=false;
	}  
	if(xwei=='A'||xwei=='B'||xwei=='C'){
		xl=true;
	}
	else{
		xl=false;
	}  
	if(rl == xl && ok){
		cout<<"1";
	}
	else{
		cout<<"0";
		ok=0;
	}
	if(ok){
		if(rl==1){
			if(abs(xwei-rwei)==1) cout<<"1";
			else cout<<"0";
		}
		else cout<<"1";
	} 
	else cout<<"0";
	return 0;
}
