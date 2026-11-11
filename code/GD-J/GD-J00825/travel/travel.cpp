#include<bits/stdc++.h>
using namespace std;
int fc(char c){
	return c>='D';
} 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,t,ss,tt;
	cin>>s>>t>>ss>>tt;
	if(s==ss){
		cout<<"1";
		if(t[0]==tt[0] && t[1]==tt[1]){
			cout<<"1";
			if(fc(t[2])==fc(tt[2])){
				cout<<"1";
				if(abs(t[2]-tt[2])==1){
					cout<<"1"; 
				}
				else{
					cout<<"0";
				}
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
