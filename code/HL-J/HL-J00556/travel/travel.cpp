#include<bits/stdc++.h>
using namespace std;
string as,bs,ah,bh;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>as>>ah>>bs>>bh;
		if(as==bs){
			cout<<"1";
			if((ah[0]==bh[0]) && (ah[1]==bh[1])){
				cout<<"1";
				if((ah[2]=='A'|| ah[2]=='B'||ah[2]=='C' && bh[2]=='A'|| bh[2]=='B'||bh[2]=='C') || (ah[2]=='D'|| ah[2]=='F' && bh[2]=='D'|| bh[2]=='F')){
					cout<<"1";
					if(ah[2]-'0'+1==bh[2]-'0' ||ah[2]-'0'-1==bh[2]-'0' ){
						cout<<"1";
					}
				else{
					cout<<"0";
					}
			}
			else{
				cout<<"0"<<"0";
				return 0;
				}
		}
		else{
			cout<<"0"<<"0"<<"0";
			return 0;
			}
		}
			else{
				cout<<"0"<<"0"<<"0"<<"0";
				return 0;
				}
			
return 0;
}


