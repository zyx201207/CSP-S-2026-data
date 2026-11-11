#include <bits/stdc++.h>
using namespace std;
 
int main(){
	freopen("travel.in","r",stdio);
	freopen("travel.out","w",stdio);
	string s,ss,sss,ssss;
	cin>>s>>ss>>sss>>ssss;
	if(s!=sss){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	int n=(ss[0]-'0')*10+(ss[1]-'0');
	int m=(ssss[0]-'0')*10+(ssss[1]-'0');
	if(n!=m){
		cout<<"000";
		return 0;
	}
	cout<<1;
	char c=ss[2],cc=ssss[2];
	if(((c=='A')||(c=='B')||(c=='C'))&&((cc=='D')||(cc=='F'))){
		cout<<"00";
		return 0;
	}
	if(((cc=='A')||(cc=='B')||(cc=='C'))&&((c=='D')||(c=='F'))){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if((c=='A'&&cc=='C')||(c=='C'&&cc=='A')){
		cout<<0;
	}else{
		cout<<1;
	}
	return 0;
} 
