#include <bits/stdc++.h>
using namespace std;
string x,y;
string sx,sy;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>sx>>y>>sy;
	if(x==y){
		cout<<1;
		if(sy[0]==sx[0]&&sy[1]==sx[1]){
			cout<<1;
			if((sx[2]>'C'&&sy[2]>'C')||(sx[2]<='C'&&sy[2]<='C')){
				cout<<1;
				if((sx[2]=='A'&&sy[2]=='B')||(sx[2]=='B'&&sy[2]=='A')||(sx[2]=='B'&&sy[2]=='C')||(sx[2]=='C'&&sy[2]=='B')||(sx[2]=='E'&&sy[2]=='F')||(sx[2]=='F'&&sy[2]=='E')){
				
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
	    else{
	    	cout<<"000";
		}
	    	
	}
	else{
		cout<<"0000";
	}
		
		
}
