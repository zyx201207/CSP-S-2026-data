#include<bits/stdc++.h>
using namespace std;

int number(char a){
	if(a=='A') return 1;
	else if(a=='B') return 2;
	else if(a=='C') return 3;
	else if(a=='D') return 4;
	else if(a=='F') return 5;
	else return -1;
	
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int xR,xX;
	char s1[3],s2[3];
	int c1,c2;
	cin>>c1;
	
		
	
	for(int i=0;i<3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=0;i<3;i++){
		cin>>s2[i];
	}
	xR=number(s1[2]);
	xX=number(s2[2]);
	
	
	if(c1==c2) {
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {
	
			cout<<"1";
			if((xR<=3&&xX<=3)||(xR>3&&xX>3)) {
			
				cout<<"1";
				if(xR+1==xX||xX+1==xR) {
					cout<<"1";
				}
				else cout<<"0";
			}
			
			else cout<<"00";
			
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}











