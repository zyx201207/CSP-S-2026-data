#include<bits/stdc++.h>
using namespace std;
string s,sc,c,ch;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>sc>>c>>ch;
	if(s==c){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(sc[0]==ch[0]&&sc[1]==ch[1]){
		cout<<"1";
		if(sc[2]=='A'){
			if(ch[2]=='B'){
				cout<<"11";
			}else if(ch[2]=='C'){
				cout<<"10";
			}else{
				cout<<"00";
			}
		}
		if(sc[2]=='B'){
			if(ch[2]=='A'||ch[2]=='C'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}
		if(sc[2]=='C'){
			if(ch[2]=='B'){
				cout<<"11";
			}else if(ch[2]=='A'){
				cout<<"10";
			}else{
				cout<<"00";
			}
		}
		if(sc[2]=='D'){
			if(ch[2]=='F'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}
		if(sc[2]=='F'){
			if(ch[2]=='D'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}
	}else{
		cout<<"000";
	}
	return 0;
}
