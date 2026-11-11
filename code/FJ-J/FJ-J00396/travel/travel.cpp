#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	int p=stoi(a),q=stoi(c);
	if(p!=q){
		cout<<"0000";
		return 0;
	}
	string r="1";
	if(b[0]==d[0]&&b[1]==d[1]){
		r+="1";
	}
	else{
		r+="000";
		cout<<r;
		return 0;
	}
	if((b[2]=='C'&&d[2]=='D')||(b[2]=='D'&&d[2]=='C')){
		r+="00";
		cout<<r;
		return 0;
	}
	else{
		r+="1";
	}
	if(abs(b[2]-d[2])==1){
		r+="1";
		cout<<r;
	}
	else{
		r+="0";
		cout<<r;
	}
	return 0;
} 
