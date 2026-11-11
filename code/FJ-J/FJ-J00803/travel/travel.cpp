#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(b[2]<='C'&&d[2]<='C'){
		if(b[2]=='B'||d[2]=='B'){
			cout<<"11";
			return 0;
		}else{
			cout<<"10";
			return 0;
		}
	}else if(b[2]>'C'&&d[2]>'c'){
		cout<<"11";
		return 0;
	}else{
		cout<<"00";
		return 0;
	}
	return 0;
}
