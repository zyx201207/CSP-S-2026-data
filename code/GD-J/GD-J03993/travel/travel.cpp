#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c,cc;
	string s,ss;
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<1;
		if(s[0]==ss[0]&&s[1]==ss[1]){
			cout<<1;
			if(s[2]-'A'<=2&&ss[2]-'A'<=2){
				cout<<1;
				if(s[2]=='B'||ss[2]=='B'){
					cout<<1;
					return 0;
				}
				else {
					cout<<0;
					return 0;
				}
			}
			else if((s[2]-'A'>2&&ss[2]-'A'>2)){
				cout<<"11";
				return 0;
			}
			else {
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else {
		cout<<"0000";
		return 0;
	}
}
