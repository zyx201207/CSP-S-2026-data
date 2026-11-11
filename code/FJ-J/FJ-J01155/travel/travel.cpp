#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,m,x,y;
	cin>>n>>m>>x>>y;
	if(n==x){
		cout<<1;
		if(m[0]==y[0]&&m[1]==y[1]){
			cout<<1;
			if(m[2]>'C'&&y[2]>'C'){
				cout<<1;
				if(m[2]-y[2]==1||y[2]-m[2]==1){
					cout<<1;
				}
				else{cout<<0;
				}
			}
			else if(m[2]<='C'&&y[2]<='C'){
				cout<<1;
				if(m[2]-y[2]==1||y[2]-m[2]==1){
					cout<<1;
				}
				else{cout<<0;
				}
			}
			else {cout<<"00";
			}
		}
		else{cout<<"000";
	}
		
		
	}
	else{cout<<"0000";
	}
	
	

	
	
	
	
	
	return 0;
}
