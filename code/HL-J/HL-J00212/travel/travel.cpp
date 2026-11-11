#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cx,sx,cy,sy;
	cin>>cx>>sx>>cy>>sy;
	if(cx==cy){
		cout<<1;
		if(sx[0]==sy[0] && sx[1]==sy[1]){
			cout<<1;
			if(((sx[2]>='A' && sx[2]<='C') && (sy[2]>='A' && sy[2]<='C')) || ((sx[2]>='D' && sx[2]<='F') && (sy[2]>='D' && sy[2]<='F'))){
				cout<<1;
				if((sx[2]>='D' && sx[2]<='F') && (sy[2]>='D' && sy[2]<='F')){
					cout<<1;
					return 0;
				}
				else if((sx[2]=='A' && sy[2]=='C') || (sx[2]=='C' && sy[2]=='A')){
					cout<<0;
					return 0;
				}
				else{
					cout<<1;
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