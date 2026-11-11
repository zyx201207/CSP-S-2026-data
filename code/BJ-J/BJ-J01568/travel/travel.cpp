#include<bits/stdc++.h>
using namespace std;
int r,x;
string zr,zx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>zr>>x>>zx;
	if(r==x){
		if(zr[0]==zx[0] && zr[1]==zx[1]){
			if(((zr[2]=='A' || zr[2]=='B' || zr[2]=='C') && (zx[2]=='A' || zx[2]=='B' || zx[2]=='C'))||((zr[2]=='D' || zr[2]=='F') && (zx[2]=='D' || zx[2]=='F'))){
				if(abs(int(zr[2])-int(zx[2]))==1){
					cout<<"1111";
				}
				else{
					cout<<"1110";
					}
			}
			else{
				cout<<"1100";
				}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
