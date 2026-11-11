#include<bits/stdc++.h>
using namespace std;
string s,ss,sss,ssss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>s>>ss>>sss>>ssss;
	if(s==sss) cout<<'1';
	else cout<<'0';
	if(s==sss&&ss[0]==ssss[0]&&ss[1]==ssss[1]) cout<<'1';
	else cout<<'0';
	if(ss[0]==ssss[0]&&ss[1]==ssss[1]){
		if((ss[2]=='A'&&ssss[2]=='B')||(ss[2]=='A'&&ssss[2]=='C')||(ss[2]=='B'&&ssss[2]=='C')){
			cout<<'1';
		}
		else if((ss[2]=='B'&&ssss[2]=='A')||(ss[2]=='C'&&ssss[2]=='A')||(ss[2]=='C'&&ssss[2]=='B')){
			cout<<'1';
		}
		else if((ss[2]=='D'&&ssss[2]=='F')||(ss[2]=='F'&&ssss[2]=='D')){
			cout<<'1';
		}
		else cout<<'0';
	}
	else cout<<'0';
	if(ss[0]==ssss[0]&&ss[1]==ssss[1]){
		if((ss[2]=='A'&&ssss[2]=='B')||(ss[2]=='B'&&ssss[2]=='C')){
			cout<<'1';
		}
		else if((ss[2]=='B'&&ssss[2]=='A')||(ss[2]=='C'&&ssss[2]=='B')){
			cout<<'1';
		}
		else if((ss[2]=='D'&&ssss[2]=='F')||(ss[2]=='F'&&ssss[2]=='D')){
			cout<<'1';
		}
		else cout<<'0';
	}
	else cout<<'0';
	return 0;
}
//Trick||Treat!
