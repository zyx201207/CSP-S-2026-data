#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(c2[0]==c4[0]&&c2[1]==c4[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((c2[2]=='F'&&c4[2]=='D')||(c4[2]=='F'&&c2[2]=='D')){
		cout<<11;
	}else{
		if((c2[2]=='A'&&c4[2]=='B')||(c2[2]=='B'&&c4[2]=='C')||(c4[2]=='A'&&c2[2]=='B')||(c4[2]=='B'&&c2[2]=='C')){
			cout<<"11";
		}else if((c2[2]=='A'&&c4[2]=='C')||(c4[2]=='A'&&c2[2]=='C')){
			cout<<"10";
		}else{
			cout<<"00";
		}
	}
	return 0;
}

