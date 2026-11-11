#include <iostream>
#include <cstring>
using namespace std;
string rr,rrr;
char xxx[4],xx[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rr>>xx>>rrr>>xxx;
	if(rr==rrr){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(xx[0]==xxx[0]&&xx[1]==xxx[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(xx[2]<='C'&&xxx[2]<='C'){
		cout<<"1";
	}
	else if(xx[2]>'C'&&xx[2]>'C'){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	int tt;
	int kk=xx[2];
	int ll=xxx[2];
	if(kk>ll) tt=kk-ll;
	else tt=ll-kk;
	if(tt==1) cout<<"1";
	else cout<<"0";
	return 0;
}
