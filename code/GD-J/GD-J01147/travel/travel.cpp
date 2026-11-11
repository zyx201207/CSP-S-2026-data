#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
string a1,b1,a2,b2,a3,b3;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b)cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<a1.size()-1;i++){
		if(a1[i]!=b1[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if(a1[2]=='A'&&b1[2]=='B'){
		cout<<"11";
	}
	else if(a1[2]=='B'&&b1[2]=='A'){
		cout<<"11";
	}
	else if(a1[2]=='A'&&b1[2]=='C'){
		cout<<"10";
	}
	else if(a1[2]=='C'&&b1[2]=='A'){
		cout<<"10";
	}
	else if(a1[2]=='B'&&b1[2]=='C'){
		cout<<"11";
	}
	else if(a1[2]=='C'&&b1[2]=='B'){
		cout<<"11";
	}
	else if(a1[2]=='D'&&b1[2]=='F'){
		cout<<"11";
	}
	else if(a1[2]=='F'&&b1[2]=='D'){
		cout<<"11";
	}
	else cout<<"00";
	return 0;
} 
