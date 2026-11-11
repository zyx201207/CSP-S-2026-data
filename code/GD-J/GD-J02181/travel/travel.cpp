#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cx1,cx2;
	string zw1,zw2,shuzi1,shuzi2;
	char zimu1,zimu2;
	cin>>cx1>>zw1>>cx2>>zw2;
	shuzi1=zw1[0];
	shuzi1+=zw1[1];
	shuzi2=zw2[0];
	shuzi2+=zw2[1];
	zimu1=zw1[2];
	zimu2=zw2[2];
	if(cx1==cx2){
		cout<<"1";
		if(shuzi1==shuzi2){
			cout<<"1";
			if(zimu1<='C' && zimu2<='C' || zimu1>='D' && zimu2>='D'){
				cout<<"1";
				if(zimu1==zimu2-1 ||zimu1==zimu2+1 || zimu1=='D'&&zimu2=='F' || zimu1=='F' && zimu2=='D'){
					cout<<"1";
				}
				else{
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
	}
	else{
		cout<<"0000";
	}
	
	
	return 0;
} 
