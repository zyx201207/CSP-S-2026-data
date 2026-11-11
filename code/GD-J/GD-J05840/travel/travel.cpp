#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,r,xx,rr;
	cin>>r>>rr>>x>>xx;
	int xi=(x[0]-'0')*10+(x[1]-0),xxi=(xx[0]-'0')*10+(xx[1]-0),ri=(r[0]-'0')*10+(r[1]-0),rri=(rr[0]-'0')*10+(rr[1]-0);
	int nx=xx[2]-'A'+1,nr=rr[2]-'A'+1;
	if(xi==ri){
		cout<<"1";
		if(xxi==rri){
			cout<<"1";
			if((nx<4&&nr<4)||(nx>3&&nr>3)){
				cout<<"1";
				if(abs(nx-nr)==1){
					cout<<"1";
					return 0;
				}
				else{
					cout<<"0";
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
