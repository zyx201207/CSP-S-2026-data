#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rs>>xc>>xs;
	if(rc==xc) cout<<1;
	else{
		cout<<0000;
		return 0;
	}

		if(rc==xc&&rs[0]==xs[0]&&rs[1]==xs[1]){
			cout<<1;
			if(rs[2]=='A'||rs[2]=='B'||rs[2]=='C'){
				if(xs[2]=='D'||xs[2]=='F'){
					cout<<00;
					return 0;
				}
				else{
					cout<<1;
					if(rs[2]-xs[2]==1||xs[2]-rs[2]==1) cout<<1;
				    else if(rs[2]-xs[2]!=1||xs[2]-rs[2]!=1){
				    	cout<<00;
				    	return 0;
					}
				}
			}
		
			else if(xs[2]=='A'||xs[2]=='B'||xs[2]=='C'){
				if(rs[2]=='D'||rs[2]=='F'){
					cout<<00;
					return 0;
				}
				else{
					cout<<1;
					if(rs[2]-xs[2]==1||xs[2]-rs[2]==1) cout<<1;
					else if(rs[2]-xs[2]!=1||xs[2]-rs[2]!=1){
						cout<<00;
						return 0;
					}
				}
			}	
			else cout<<000;
		}
	
	
	
	return 0;
}
