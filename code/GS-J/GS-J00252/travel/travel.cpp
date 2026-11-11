#include <bits/stdc++.h>
using namespace std;
string cr,cx,r,x;
bool pd(){
	for(int i=0;i<2;i++){
		if(r[i]!=x[i]) return 0;
	}
	return 1;
}//02 02B 02 01A 1000
//02 01A 03 01A 0000
//02 01C 02 01D 1100
//02 01C 02 01A 1110
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>cr>>r>>cx>>x;
	if(cr!=cx){
		cout<<"0000";
	}
	else{
		cout<<1;
		if(!pd()) {
			cout<<"000";
		}
		else{
			cout<<1;
			if((r[2]<'D'&&x[2]<'D')||(r[2]>'C'&&x[2]>'C')){
				cout<<1;
				if(r[2]+1==x[2]||x[2]+1==r[2]){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
	}
	return 0;
}
