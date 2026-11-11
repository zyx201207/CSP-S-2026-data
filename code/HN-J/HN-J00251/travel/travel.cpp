#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1;
	string a2,b2;
	cin>>a1>>a2>>b1>>b2;
	int a=(a2[0]-'0')*10+(a2[1]-'0');
	int b=(b2[0]-'0')*10+(b2[1]-'0');
	if(a1==b1){
		cout<<"1";	
	}else{
		cout<<"0000";
		return 0;
	}
	if(a==b){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	int a3=(a2[2]-'A');
	int b3=(b2[2]-'A');
	int maxx=max(a3,b3);
	if(maxx<=2){
		cout<<"1";
	}else if((a2[2]=='D'&&b2[2]=='E')||(b2[2]=='D'&&a2[2]=='E')){
		cout<<"11";
		return 0;
	}else{
		cout<<"00";
		return 0;
	}
	if(abs(a3-b3)==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
    return 0;
}

