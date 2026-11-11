#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r2,x2,r1,x1;
	cin>>r1>>r2>>x1>>x2;
	if(r1!=x1){
		cout<<"0000";
		return 0;
	}
	else if(r2.substr(0,2)!=x2.substr(0,2)){
		cout<<"1000";
		return 0;
	}
	else if(r2[2]>='A'&&r2[2]<='C'){
		if(x2[2]>='D'&&x2[2]<='E'){
			cout<<"1100";
			return 0;
		}
	}
	else if(r2[2]>='D'&&r2[2]<='E'){
		if(x2[2]>='A'&&x2[2]<='C'){
			cout<<"1100";
			return 0;
		}
	}
	//char a=r2[2],b=x2[2];
	//cout<<a<<b;
	if(r2[2]=='A'){
		if(x2[2]=='B'){
			cout<<"1111";
			return 0;
		}
	}
	else if(r2[2]=='C'){
		if(x2[2]=='B'){
			cout<<"1111";
			return 0;
		}
	}
	else if(r2[2]=='B'){
		if(x2[2]=='A'||x2[2]=='C'){
			cout<<"1111";
			return 0;
		}
	}
	else if(r2[2]=='D'){
		if(x2[2]=='E'){
			cout<<"1111";
			return 0;
		}	
	}
	else if(r2[2]=='E'){
		if(x2[2]=='D'){
			cout<<"1111";
			return 0;
		}
	}
	cout<<"1110";	
	return 0;
}
