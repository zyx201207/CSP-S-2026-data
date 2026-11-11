#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int j1=0,k1=0,j2=0,k2=0,jj=0;
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3) cout <<'1';
	else {
		cout<<"0000";
		return 0; 
	}
	if(c2[0]==c4[0] && c2[1]==c4[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(c2[2]>='A' && c2[2]<='C'){
		j1=1;
	}
	else if(c2[2]=='D' || c2[2]=='F'){
		k1=1;
	}
	if(c4[2]>='A' && c4[2]<='C'){
		j2=1;
	}
	else if(c4[2]=='D' || c4[2]=='F'){
		k2=1;
	}
	if(j1==1 && j2==1){
		cout<<'1';
	}
	else if(k1==1 && k2==1){
		cout<<"11";
		return 0;
	}
	else{
		cout <<"00";
		return 0;
	} 
	if(c2[2]=='A' && c4[2]=='C'){
		jj=1;
	}
	else if(c4[2]=='A' && c2[2]=='C'){
		jj=1;
	}
	if(jj==1){
		cout<<'0';
	}
	else{
		cout<<"1";	
	}

	return 0;
} 
