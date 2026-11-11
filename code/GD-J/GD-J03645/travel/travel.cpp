#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s[10];
	for(int i=1;i<=4;i++){
		cin>>s[i];
	}
	if(s[1]==s[3]){
		cout<<1;
		if(s[2][0]==s[4][0] && s[2][1]==s[4][1]){
			cout<<1;
			if((s[2][2]-'A'<3 && s[4][2]-'A'<3) ||(s[2][2]-'A'>=3 && s[4][2]-'A'>=3)){
				cout<<1;
				if(abs((s[2][2]-'A')-(s[4][2]-'A'))==1)cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
} 
