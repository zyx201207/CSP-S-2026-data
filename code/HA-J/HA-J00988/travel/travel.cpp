#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<'1';
		if(b.substr(0,2)==d.substr(0,2)){
		cout<<'1';
		if(b[2]=='A'||b[2]=='B'||b[2]=='C'&&d[2]=='A'||d[2]=='B'||d[2]=='C'){
		cout<<'1';
		if(b[2]+1==d[2]||b[2]-1==d[2]){
			cout<<'1';
			return 0;
		}else{
			cout<<'0';
		}
	}else if(b[2]=='D'||b[2]=='F'&&d[2]=='D'||d[2]=='F'){
		cout<<"11";
		return 0;
	}else{
		cout<<"00";
	}
	}else{
		cout<<"000";
	}
	}else{
		cout<<"0000";
	}
	
	
	
	
	
	return 0;
}
