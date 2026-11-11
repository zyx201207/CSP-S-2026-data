#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		int rp,xp;
		rp=(b[0]-'0')*10+(b[1]-'0');
		xp=(d[0]-'0')*10+(d[1]-'0');
		if(rp==xp){
			cout<<1;
//			cout<<"a";
			char rr=b[2],xx=d[2];
			if((rr>='A'&&rr<='C'&&xx>='A'&&xx<='C')||(rr>='D'&&rr<='E'&&xx>='D'&&xx<='E')){
				cout<<1;
//				cout<<"a";
				if(!((rr=='A'&&xx=='C')||(rr=='C'&&xx=='A'))){
					cout<<1;
				}else{
					cout<<0;
					return 0;
				}
			}else{
//				cout<<"a";
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
