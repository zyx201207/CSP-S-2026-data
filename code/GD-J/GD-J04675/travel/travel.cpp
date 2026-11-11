#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string as,bs;
	int ac,bc;
	cin>>ac>>as>>bc>>bs;
	int an=as[2],bn=bs[2];
	if(ac==bc){
		cout<<"1";
		if(as[0]==bs[0]&&as[1]==bs[1]){
			cout<<"1";
			if((an>=65&&an<=67)&&(bn>=65&&bn<=67)){
				cout<<"1";
				if(an-bn==-1|an-bn==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if((an>=68&&an<=70)&&(bn>=68&&bn<=70)){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
