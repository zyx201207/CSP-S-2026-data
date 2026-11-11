#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	int sl,ssl;
	cin>>c>>s>>cc>>ss;
	if(s[2]=='A') sl=1;
	else if(s[2]=='B') sl=2;
	else if(s[2]=='C') sl=3;
	else if(s[2]=='D') sl=5;
	else if(s[2]=='F') sl=6;
	if(ss[2]=='A') ssl=1;
	else if(ss[2]=='B') ssl=2;
	else if(ss[2]=='C') ssl=3;
	else if(ss[2]=='D') ssl=5;
	else if(ss[2]=='F') ssl=6;
	if(c==cc){
		cout<<"1";
		if(s[0]==ss[0]&&s[1]==ss[1]){
			cout<<"1";
			if((sl>=1&&sl<=3&&ssl>=1&&ssl<=3)||(sl>=5&&sl<=6&&ssl>=5&&ssl<=6)){
				cout<<"1";
				if((sl+1)==ssl||(ssl+1)==sl){
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
