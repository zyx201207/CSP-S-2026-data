#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,ss,n,nn;
	cin>>s>>ss>>n>>nn;
	if(s!=n){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		if(ss[0]==nn[0]&&ss[1]==nn[1]){
			cout<<"1";
			char x=ss[2],y=nn[2];
			if((ss[2]=='A'&&nn[2]=='B')||(ss[2]=='B'&&nn[2]=='A')){
				cout<<"11";
			}
			if((ss[2]=='A'&&nn[2]=='C')||(ss[2]=='C'&&nn[2]=='A')){
				cout<<"10";
			}
			if((ss[2]=='A'&&nn[2]=='D')||(ss[2]=='D'&&nn[2]=='A')){
				cout<<"00";
			}
			if((ss[2]=='A'&&nn[2]=='F')||(ss[2]=='F'&&nn[2]=='A')){
				cout<<"00";
			}
			if((ss[2]=='B'&&nn[2]=='C')||(ss[2]=='C'&&nn[2]=='B')){
				cout<<"11";
			}
			if((ss[2]=='B'&&nn[2]=='D')||(ss[2]=='D'&&nn[2]=='B')){
				cout<<"00";
			}
			if((ss[2]=='B'&&nn[2]=='F')||(ss[2]=='F'&&nn[2]=='B')){
				cout<<"00";
			}
			if((ss[2]=='C'&&nn[2]=='D')||(ss[2]=='D'&&nn[2]=='C')){
				cout<<"00";
			}
			if((ss[2]=='C'&&nn[2]=='F')||(ss[2]=='F'&&nn[2]=='C')){
				cout<<"00";
			}
			if((ss[2]=='D'&&nn[2]=='F')||(ss[2]=='F'&&nn[2]=='D')){
				cout<<"11";
			}
		}
		else{
			cout<<"000";
		}
	}
	return 0;
}
