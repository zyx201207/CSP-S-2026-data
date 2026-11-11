#include<bits/stdc++.h>
using namespace std;


string a,b,c,d;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if(b[2]=='C'&&d[2]=='D'){
		cout<<"00";
		return 0;
	}
	else if(b[2]=='D'&&d[2]=='C'){
		cout<<"00";
		return 0;
	}
	else if(b[2]=='A'&&d[2]=='E'){
		cout<<"00";
		return 0;
	}
	else if(b[2]=='E'&&d[2]=='A'){
		cout<<"00";
		return 0;
	}
	else if(abs(b[2]-d[2])<=2){
		cout<<"1";
		
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(b[2]-d[2])==1)
		cout<<"1";
	else{
		cout<<"0";
	}
	
	return 0;
}







//谁懂半小时切T1的致命感8：59 








