#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rh,xc,xh;
	cin>>rc>>rh>>xc>>xh;
	if(rc!=xc){
		cout<<"0000";
		return 0;
	}else{
		if((rh[0]!=xh[0]) || (rh[1]!=xh[1])){
			cout<<"1000";
			return 0;
		}else{
			if((rh[2]=='D' && xh[2]=='F') || (rh[2]=='F' && xh[2]=='D')){
				cout<<"1111";
				return 0;
			}else{
				if((rh[2]<='C' && xh[2]<='C') && (rh[2]>='A' && xh[2]>='A')){
					if(abs((int)(rh[2]-xh[2]))==1){
						cout<<"1111";
						return 0; 
					}else{
						cout<<"1110";
						return 0;
					}
				}else{
					cout<<"1100";
					return 0;
				}
			}
		}
	}
	return 0;
}
