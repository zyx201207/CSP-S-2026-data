#include<bits/stdc++.h>
using namespace std;
int rc;
int xc;
string rz,xz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>rc>>rz>>xc>>xz;
	}
	if(rc==xc){
		cout << 1;
		if(rz[1]==xz[1]){
			cout << 1; 
			if(rz[2]+1==xz[2]||rz[2]-1==xz[2]){
				cout<<11;
			}
			else{
				cout<<10;
			}
		}
		else{
			cout <<000;
			return 0;
		}
	}
	else{
		cout<<0000;
		return 0;
	}
	
	return 0;
}
