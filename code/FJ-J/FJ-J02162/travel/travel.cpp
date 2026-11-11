#include<bits/stdc++.h>
using namespace std;

string a1,a2,b1,b2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	bool ans1=(a1==b1);
	cout<<ans1;
	if(!ans1){
		cout<<"000";
		return 0;
	}
	bool ans2=(a2[0]+a2[1]==b2[0]+b2[1]);
	cout<<ans2;
	if(!ans2){
		cout<<"00";
		return 0;
	}
	
	bool ans3=0;
	if((a2[2]>'C')==(b2[2]>'C')){
		ans3=1;
	}
	cout<<ans3;
	if(!ans3){
		cout<<"0";
		return 0;
	}
	bool ans4=0;
	if(a2[2]>'C'){
		ans4=1;
	}else{
		ans4=((a2[2]=='B')||(b2[2]=='B'));
	}
	cout<<ans4;
	return 0;
}
