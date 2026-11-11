#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
string at1,at2,bt1,bt2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<1;
		at1=a2[0]+a2[1],at2=a2[2];
		bt1=b2[0]+b2[1],bt2=b2[2];
		if(at1==bt1){
			cout<<1;
			if( ( (at2=="A"||at2=="B"||at2=="C") && (bt2=="A"||bt2=="B"||bt2=="C") ) || ( (at2=="D"||at2=="F") && (bt2=="D"||bt2=="F") ) ){
				cout<<1;
				if( ( (at2=="A"&&bt2=="B") || (at2=="B"&&bt2=="A") ) || ( (at2=="B"&&bt2=="C") || (at2=="C"&&bt2=="B") ) || ( (at2=="D"&&bt2=="F") || (at2=="F"&&bt2=="D") ) ){
					cout<<1;
				}else{
					cout<<0;
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
