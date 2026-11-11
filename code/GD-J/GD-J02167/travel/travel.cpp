#include<bits/stdc++.h>
using namespace std;
string cx1,cx2,zw1,zw2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>zw1>>cx2>>zw2;
	if(cx1==cx2){
		cout<<1;
		string zwp1,zwp2;
		char zwh1,zwh2;
		zwp1=zw1[0]+zw1[1];
		zwp2=zw2[0]+zw2[1];
		zwh1=zw1[2];
		zwh2=zw2[2];
		if(zwp1==zwp2){
			cout<<1;
			if(((zwh1>='A'&&zwh1<='C')&&(zwh2>='A'&&zwh2<='C'))||((zwh1>='D'&&zwh1<='F')&&(zwh2>='D'&&zwh2<='F'))){
				cout<<1;
				if((zwh1>='A'&&zwh1<='C')&&(zwh2>='A'&&zwh2<='C')){
					if(abs(int(zwh1)-int(zwh2))==1){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
				else{
					cout<<1;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	} 
	else{
		cout<<"0000";
	}
	return 0;
}
