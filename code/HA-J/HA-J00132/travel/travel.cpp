#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string cf,cs,zf,zs;
	cin>>cf>>zf>>cs>>zs;
	bool check=false;
	bool ok=true;
	if(cf==cs){
		cout<<1;
		check=true;
	}else{
		cout<<"0000";
		return 0;
	}
	
	
	for(int i=0;i<2;i++){
		if(zf[i]!=zs[i]){
			ok=false;
		}
	}
	if(ok==true&&check==true){
		cout<<1;
	}else if(check==true&&ok==false){
		cout<<"000";
		return 0;
	}
	
	
	if('A'<=zs[2]&&zs[2]<='C'&&'A'<=zf[2]&&zf[2]<='C'&&zf[2]!=zs[2]){
		cout<<1;
	}else if((zf[2]=='D'&&zs[2]=='F')||(zf[2]=='F'&&zs[2]=='D')){
		cout<<11;
		return 0;
	}else{
		cout<<"00";
		return 0;
	}
	
	
	if((zf[2]=='A'&&zs[2]=='B')||(zf[2]=='B'&&zs[2]=='A')||(zf[2]=='B'&&zs[2]=='C')||(zf[2]=='C'&&zs[2]=='B')){
		cout<<;
	}else{
		cout<<"0";
	}
	return 0;
}
