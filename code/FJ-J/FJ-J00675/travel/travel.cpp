#include <bits/stdc++.h>
using namespace std;
string c,cc,s,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<1;
		if(s[0]==ss[0]&&s[1]==ss[1]){
			cout<<1;
			if((ss[2]-'A'<=2&&s[2]-'A'<=2)||(ss[2]-'A'>=3&&s[2]-'A'>=3)){
				cout<<1;
				if(abs(s[2]-ss[2])==1||(s[2]=='D'||ss[2]=='D')){
					cout<<1;
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
