#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travle.in","r",stdin);
	freopen("travle.out","w",stdout);
	ios::sync_with_stdio,cin.tie(0),cout.tie(0);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s2[0]==s4[0]){
		if(s2[1]==s4[1]){
			cout<<1;
		}
		else {
			cout<<"000";
			return 0;
		}
		if('A'<=s2[2]&&s2[2]<='C'&&'A'<=s4[2]&&s4[2]<='C'){
			cout<<1;
			if(s4[2]==s2[2]+1||s4[2]==s2[2]-1){
				cout<<1;
			}
			else cout<<0;
		}
		else if('D'<=s2[2]&&s2[2]<='E'&&'D'<=s4[2]&&s4[2]<='F'){
			cout<<1;
			if(s4[2]==s2[2]+1||s4[2]==s2[2]-1){
				cout<<1;
			}
			else cout<<0;
		}
		else cout<<"00";
	}
	else cout<<"000";
	return 0;
}
