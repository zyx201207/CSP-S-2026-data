#include<bits/stdc++.h>
using namespace std;
string c,c2,s,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c2>>s2;
	if(c==c2){
		if(s[0]==s2[0]&&s[1]==s2[1]){
			if((s[2]<='C'&&s2[2]<='C')||(s[2]>'C'&&s2[2]>'C')){
				if(s[2]>'C'){
					cout<<"1111";
				}
				else{
					if(min(s[2],s2[2])+1==max(s[2],s2[2])) cout<<"1111";
					else cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
}
