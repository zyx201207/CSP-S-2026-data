#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<"1";
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			cout<<"1";
			if((s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D')){
				cout<<"11";
			}
			else if((s2[2]=='A'&&s4[2]=='B')||(s2[2]=='B'&&s4[2]=='A')){
				cout<<"11";
			}
			else if((s2[2]=='B'&&s4[2]=='C')||(s2[2]=='C'&&s4[2]=='B')){
				cout<<"11";
			}
			else if((s2[2]=='A'&&s4[2]=='C')||(s2[2]=='C'&&s4[2]=='A')){
				cout<<"10";
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
/*

*/
