#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string crr1,crr2,srr1,srr2;
	cin>>crr1>>srr1>>crr2>>srr2;
	if(crr1!=crr2){
		cout<<"0000";
	}else{
		cout<<"1";
		if(srr1[0]==srr2[0] && srr1[1]==srr2[1]){
			cout<<"1";
			if(
			((srr1[2]=='A' || srr1[2]=='B' || srr1[2]=='C') && (srr2[2]=='A' || srr2[2]=='B' || srr2[2]=='C'))
			 || ((srr2[2]=='F' || srr2[2]=='D')&&(srr1[2]=='D' || srr1[2]=='F'))
			 ){
				cout<<"1";
				if(srr1[2]=='A'){
					if(srr2[2]=='B'){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else if(srr1[2]=='B'){
					if(srr2[2]=='A' || srr2[2]=='C'){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else if(srr1[2]=='C'){
					if(srr2[2]=='B'){
						cout<<"1";
					}else{
						cout<<"0";
					} 
				}else if(srr1[2]=='D'){
					if(srr2[2]=='E'){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else if(srr1[2]=='E'){
					if(srr2[2]=='D'){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}
	return 0;
}
