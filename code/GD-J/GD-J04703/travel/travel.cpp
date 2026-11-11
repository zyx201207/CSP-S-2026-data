#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string rx,r,xx,x;
    cin>>rx>>r>>xx>>x;
    if(rx==xx){
    	string rp=r.substr(0,2),xp=x.substr(0,2),rc=r.substr(2,1),xc=x.substr(2,1);
    	if(rp==xp){
    		if((rc[0]<='C' && xc[0]<='C')||(rc[0]>'C' && xc[0]>'C')){
    			if((rc[0]==xc[0]+1)||(xc[0]==rc[0]+1)){
    				cout<<"1111"<<'\n';
				}else{
					cout<<"1110"<<'\n';
				}
			}else{
				cout<<"1100"<<'\n';
			}
		}else{
			cout<<"1000"<<'\n';
		}
	}else{
		cout<<"0000"<<'\n';
	}
	return 0;
}

