#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string nr,nx,x,r;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>nr>>r>>nx>>x;
    string xr=r.substr(0,2),xx=x.substr(0,2);
    if(nr!=nx){
		cout<<"0000";
		return 0;
	}else if(xr!=xx){
		cout<<"1000";
		return 0;
	}else if((r[2]=='A'||r[2]=='B'||r[2]=='C')&&(x[2]=='D'||x[2]=='F')){
		cout<<"1100";
		return 0;
	}else if((x[2]=='A'||x[2]=='B'||x[2]=='C')&&(r[2]=='D'||r[2]=='F')){
			cout<<"1100";
			return 0;
	}else if((r[2]=='A'&&x[2]!='B')||(x[2]=='A'&&r[2]!='B'||r[2]=='B'&&(x[2]!='A'&&x[2]!='C'))||(x[2]=='B'&&(r[2]!='A'&&r[2]!='C'))||(r[2]=='C'&&x[2]!='B')||(x[2]=='C'&&r[2]!='B')||(r[2]=='D'&&x[2]!='F')||(x[2]=='D'&&r[2]!='F')||(r[2]=='F'&&x[2]!='D')||(x[2]=='F'&&r[2]!='D')){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
