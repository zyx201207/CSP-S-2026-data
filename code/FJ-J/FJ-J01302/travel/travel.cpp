#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,ss,sss,ssss;
	cin>>s>>ss>>sss>>ssss;
	if(s!=sss){
		cout<<"0000";
		return 0;
	}
	if((ss[0]!=ssss[0])||(ss[1]!=ssss[1])){
		cout<<"1000";
		return 0;
	}
	if((ss[2]<='C'&&ss[2]>='A'&&ssss[2]<='C'&&ssss[2]>='A')||(ss[2]<='F'&&ss[2]>='D'&&ssss[2]<='F'&&ssss[2]>='D')){
		if((ss[2]+1==ssss[2]||ssss[2]+1==ss[2])||((ss[2]=='D'&&ssss[2]=='F')||(ss[2]=='F'&&ssss[2]=='D'))){
			cout<<"1111";
			return 0;
		}else{
			cout<<"1110";
			return 0;
		}
		
	}else{
		cout<<"1100";
		return 0;
	}
} 
