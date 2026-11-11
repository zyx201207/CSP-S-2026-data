#include<bits/stdc++.h>
using namespace std;
string cxa,cxb,zwa,zwb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cxa>>zwa>>cxb>>zwb;
	if(cxa==cxb){
		cout<<"1";
		if(zwa[0]==zwb[0]&&zwa[1]==zwb[1]){
			cout<<"1";
			if((zwa[2]>='D'&&zwa[2]<='F'&&zwb[2]>='D'&&zwb[2]<='F')||(zwa[2]>='A'&&zwa[2]<='C'&&zwb[2]>='A'&&zwb[2]<='C')){
				cout<<"1";
				if(zwa[2]>='D'&&zwa[2]<='F'&&zwb[2]>='D'&&zwb[2]<='F'){
					cout<<"1"<<'\n';
				}else{
					int g=zwa[2]-zwb[2];
					if(abs(g)==1)cout<<"1"<<'\n';
					else cout<<"0"<<'\n';
				}
			}else cout<<"00"<<'\n';
		}else cout<<"000"<<'\n';
	}else cout<<"0000"<<'\n';
	return 0;
}
