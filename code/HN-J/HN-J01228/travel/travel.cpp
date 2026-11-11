#include<bits/stdc++.h>
#define int long long
using namespace std;
string a1,a2,b1,b2;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1=="01"||b1=="01"||a1=="16"||b1=="16"){
		cout<<"0000";
		return 0;
	}
	else if(a1==b1){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	int a=(a2[0]-'0')*10+a2[1]-'0';
	int b=(b2[0]-'0')*10+b2[1]-'0';
	if(a==b){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(a2[2]=='A'){
		if(b2[2]=='B'||b2[2]=='C'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}
	else if(a2[2]=='B'){
		if(b2[2]=='A'||b2[2]=='C'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}else if(a2[2]=='C'){
		if(b2[2]=='A'||a2[2]=='B'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}else if(a2[2]=='D'){
		if(b2[2]=='F'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}else if(a2[2]=='F'){
		if(b2[2]=='D'){
			cout<<"1";
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(a2[2]=='A'&&b2[2]=='B'){
		cout<<"1";
	}else if(a2[2]=='B'&&(b2[2]=='A'||b2[2]=='C')){
		cout<<"1";
	}else if(a2[2]=='C'&&b2[2]=='B'){
		cout<<"1";
	}else if(a2[2]=='D'&&b2[2]=='F'){
		cout<<"1";
	}else if(a2[2]=='F'&&b2[2]=='D'){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
