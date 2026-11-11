#include<bits/stdc++.h>
using namespace std;
string s[4];
bool in(char x){
	return ('A'<=x&&x<='C');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s[0]>>s[1]>>s[2]>>s[3];
	if(s[0]==s[2]){
		cout<<"1";
		if(s[1][0]==s[3][0]&&s[1][1]==s[3][1]){
			cout<<"1";
			if(in(s[1][2])==in(s[3][2])){
				cout<<"1";
				int t1=s[1][2]-'A';
				int t2=s[3][2]-'A';
				if(abs(t1-t2)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
