#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c!=cc){
		cout<<"0000"<<endl;
		return 0;
	}
	cout<<'1';
	if(s[0]==ss[0]&&s[1]==ss[1]){
		cout<<'1';
		if((s[2]=='D'&&ss[2]=='F')||(s[2]=='F'&&ss[2]=='D')){
			cout<<"11"<<endl;
			return 0;
		}
		if(s[2]=='D'||ss[2]=='F'||s[2]=='F'||ss[2]=='D'){
			cout<<"00"<<endl;
			return 0;
		}
		cout<<'1';
		if(s[2]-ss[2]==1||ss[2]-s[2]==1){
			cout<<'1'<<endl;
		}else{
			cout<<'0'<<endl;
		}
	}else{
		cout<<"000"<<endl;
		return 0;
	}
	return 0;
}
