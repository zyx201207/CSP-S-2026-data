#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	if(c==cc)cout<<"1";
	else cout<<"0";
	if(c==cc&&s[0]==ss[0]&&s[1]==ss[1])cout<<"1";
	else cout<<"0";
	if(c==cc&&s[0]==ss[0]&&s[1]==ss[1]){
		if((s[2]>='A'&&s[2]<='C'&&ss[2]>='A'&&ss[2]<='C')||(s[2]>='D'&&s[2]<='F'&&ss[2]>='D'&&ss[2]<='F')){
			cout<<"1";
		}
		else cout<<"0";
	}
	else cout<<"0";
	if(c==cc&&s[0]==ss[0]&&s[1]==ss[1]&&abs(s[2]-ss[2])==1){
		int ok=0;
		if(s[2]=='C'&&ss[2]=='D'){
			cout<<"0";
			ok=1;
		}
		if(s[2]=='D'&&ss[2]=='C'){
			cout<<"0";
			ok=1;
		}
		if(ok==0)cout<<"1";
	}else cout<<"0";
	return 0;
}
