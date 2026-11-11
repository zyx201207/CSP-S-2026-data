#include<bits/stdc++.h>
using namespace std;
string x,y,z,v; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>y>>z>>v;
	if(x==z){
		cout<<"1"; 
		if(y[0]==v[0]&&y[1]==v[1]){
			cout<<"1";
			if((y[2]=='F'||y[2]=='D')&&(v[2]=='F'||v[2]=='D')||(y[2]=='A'||y[2]=='B'||y[2]=='C')&&(v[2]=='A'||v[2]=='B'||v[2]=='C')){
				cout<<"1";
				if((y[2]=='A'&&v[2]=='B')||(y[2]=='B'&&v[2]=='A')||(y[2]=='B'&&v[2]=='C')||(y[2]=='C'&&v[2]=='B')||(y[2]=='D'&&v[2]=='F')||(y[2]=='F'&&v[2]=='D')){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 


