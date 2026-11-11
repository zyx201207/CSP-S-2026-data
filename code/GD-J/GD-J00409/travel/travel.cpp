#include<bits/stdc++.h>
using namespace std;
string c,cc,s,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<"1";
		if(s[0]==ss[0]&&s[1]==ss[1]){
			cout<<"1";
			if((s[2]>='A'&&s[2]<='C'&&ss[2]>='A'&&ss[2]<='C')||(ss[2]=='D'&&s[2]=='F')||(s[2]=='D'&&ss[2]=='F')){
				cout<<"1";
				if((ss[2]=='D'&&s[2]=='F')||(s[2]=='D'&&ss[2]=='F')||(s[2]=='A'&&ss[2]=='B')||(s[2]=='B'&&ss[2]=='A')||(s[2]=='B'&&ss[2]=='C')||(s[2]=='C'&&ss[2]=='B')) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else{
			cout<<"000";
		}
	}
	else cout<<"0000";
	
	return 0;
}
