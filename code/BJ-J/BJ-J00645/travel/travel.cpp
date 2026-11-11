#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string ra,rb,xa,xb;
	cin>>ra>>rb>>xa>>xb;
	if(ra[0]!=xa[0]||ra[1]!=xa[1]){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(xb[0]!=rb[0]||rb[1]!=xb[1]){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if(xb[2]=='A'){
		if(rb[2]!='B'&&rb[2]!='C'){
			cout<<"00";
			return 0;
		}
		if(rb[2]!='B'){
			cout<<"10";
			return 0;
		}
		if(rb[2]=='B'){
			cout<<"11";
			return 0;
		}
	}
	if(xb[2]=='B'){
		if(rb[2]!='A'&&rb[2]!='C'){
			cout<<"00";
			return 0;
		}
		if(rb[2]=='A'||rb[2]=='C'){
			cout<<"11";
		}
	}
	if(xb[2]=='C'){
		if(rb[2]!='A'&&rb[2]!='B'){
			cout<<"00";
			return 0;
		}
		if(rb[2]!='B'){
			cout<<"10";
			return 0;
		}
		if(rb[2]=='B'){
			cout<<"11";
			return 0;
		}
	}
	if(xb[2]=='D'){
		if(rb[2]!='E'){
			cout<<"00";
			return 0;
		}
		if(rb[2]=='E'){
			cout<<"11";
			return 0;
		}
	}
	if(xb[2]=='E'){
		if(rb[2]!='D'){
			cout<<"00";
			return 0;
		}
		if(rb[2]=='D'){
			cout<<"11";
			return 0;
		}
	}
	return 0;
}
