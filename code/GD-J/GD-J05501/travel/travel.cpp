#include <bits/stdc++.h>
using namespace std;
bool lr(char c){
	if(c=='A' || c=='B' || c=='C') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rx,xx,rz,xz; //小R车厢、小Z车厢、小R座位、小Z座位 
	char r,x; //小R、小Z座位
	
	cin>>rx>>rz>>r>>xx>>xz>>x;
//	cout<<rx<<' '<<rz<<' '<<r<<' '<<xx<<' '<<xz<<' '<<x<<endl;
	if(rx==xx){
		cout<<"1";
		if(rz==xz){
			cout<<"1";
			if(lr(r)==lr(x)){
				cout<<"1";
				if(abs(r-x)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
