#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int flag=0;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<1;
	if(c2[0]==c4[0] && c2[1]==c4[1]){
		cout<<1;
		if((c2[2]=='A' || c2[2]=='B' || c2[2]=='C') && (c4[2]=='A' || c4[2]=='B' || c4[2]=='C')){
			cout<<1;
			if(((c2[2]=='A' || c2[2]=='B') && (c4[2]=='A' || c4[2]=='B'))||((c2[2]=='C' || c2[2]=='B') && (c4[2]=='C' || c4[2]=='B'))){
				flag=1;
			}
		}else if((c2[2]=='D' || c2[2]=='F') && (c4[2]=='D' || c4[2]=='F') && (c2[2]=='C' || c2[2]=='B') && (c4[2]=='C' || c4[2]=='B')){
			cout<<1;
			flag=1;
		}else{
			cout<<0;
		}
		if(flag==1){
			cout<<1;
		}else{
			cout<<'0';
		}
	}else{
		cout<<'0';
		cout<<'0';
		cout<<'0';
	}

}else{
	cout<<0<<0<<0<<0;
}
	return 0;
}
