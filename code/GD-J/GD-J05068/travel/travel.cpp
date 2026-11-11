#include<bits/stdc++.h>
using namespace std;
int ca,cb,aa,ab;
char ha,hb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ca>>aa>>ha>>cb>>ab>>hb;
	if(ca==cb){
		cout<<"1";
		if(aa==ab){
			cout<<"1";
			if((ha<='C'&&hb<='C')||(ha>='D'&&hb>='D')){
				cout<<"1";
				if(abs(ha-hb)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
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
