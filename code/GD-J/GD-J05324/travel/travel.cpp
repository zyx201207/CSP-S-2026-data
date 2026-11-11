#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string sd,sf,sg,sh;
	int l=0;
	cin>>sd>>sf>>sg>>sh;
	for(int i=0;i<sd.size();i++){
		if(sd[i]!=sg[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<'1';
	
	if(sf[0]==sh[0]&&sf[1]==sh[1]){
		cout<<'1';
	}
	else{
		cout<<"000";
		return 0;
	}
	if(((sf[2]>='A'&&sf[2]<='C')&&(sh[2]>='A'&&sh[2]<='C'))||((sf[2]>='D'&&sf[2]<='F')&&(sf[2]>='D'&&sf[2]<='F'))){
		cout<<'1';
	}
	else{
		cout<<"00";
		return 0;
	}
	if((sf[2]-'0'+1==sh[2]-'0')||(sf[2]-'0'-1==sh[2]-'0')){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	return 0;
} 
