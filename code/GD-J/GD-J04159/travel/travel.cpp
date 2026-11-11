#include<bits/stdc++.h>
using namespace std;
string xc,xs,rc,rs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc){
		cout<<"1";
		if(xs[0]==rs[0]&&xs[1]==rs[1]){
			cout<<"1";
			if((xs[2]<='C'&&xs[2]>='A'&&rs[2]<='C'&&rs[2]>='A')||(xs[2]<='F'&&xs[2]>='D'&&rs[2]<='F'&&rs[2]>='D')){
				cout<<"1";
				if(xs[2]==rs[2]+1||xs[2]==rs[2]-1){
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
