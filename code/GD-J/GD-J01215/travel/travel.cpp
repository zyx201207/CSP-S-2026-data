#include<bits/stdc++.h>
using namespace std;
string s,ss,sss,ssss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s>>ss>>sss>>ssss;
	if(s!=sss){
		cout<<"0000";
	}else if(ss[0]!=ssss[0] || ss[1]!=ssss[1]){
		cout<<"1000";
	}else{
		if(ss[2]>ssss[2]){
			swap(ss[2],ssss[2]);
		}if((ss[2]=='A' && ssss[2]=='B') || (ss[2]=='B' && ssss[2]=='C') || (ss[2]=='D' && ssss[2]=='F')){
			cout<<"1111";
		}else if(ss[2]=='A' && ssss[2]=='C'){
			cout<<"1110";
		}else{
			cout<<"1100";
		}
	}
	return 0;
} 
