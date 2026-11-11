#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	string a1;
	string a2;
	string b1;
	string b2;
	cin>>a1>>a2>>b1>>b2;
	if(a1[0]==b1[0] && a1[1]==b1[1]){
		cout<<"1";
		if(a2[0]==b2[0] && a2[1]==b2[1]){
			cout<<"1";
			if((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&(b2[2]=='A'||b2[2]=='B'||b2[2]=='C')){
				cout<<"1";
				if((a2[2]+1==b2[2])||(a2[2]-1==b2[2])){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if((a2[2]=='D'||a2[2]=='F')&&(b2[2]=='D'||b2[2]=='F')){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}

