#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
   if(a[0]==c[0]&&a[1]==c[1]){
    	cout<<"1";
	}else
	if(a[0]){
	 cout<<"0000";
	 return 0;
	}
	
	if(b[1]==d[1]&&b[0]==d[0]){
		cout<<"1";
	}else
	if(a[0]){
		cout<<"000";
		return 0;
	}
	if(b[2]=='A'&&d[2]=='B'){
		cout<<"1";
	}else
	if(b[2]=='A'&&d[2]=='C'){
		cout<<"1";
	}else
	if(b[2]=='B'&&d[2]=='A'){
		cout<<"1";
	}else
	if(b[2]=='B'&&d[2]=='C'){
		cout<<"1";
	}else
	if(b[2]=='C'&&d[2]=='A'){
		cout<<"1";
	}else
	if(b[2]=='C'&&d[2]=='B'){
		cout<<"1";
	}else
	if(b[2]=='F'&&d[2]=='D'){
		cout<<"1";
	}else
	if(b[2]=='D'&&d[2]=='F'){
		cout<<"1";
	}else
	if(a[0]){
		cout<<"00";
		return 0;
	}
	if(b[2]=='A'&&d[2]=='B'){
		cout<<"1";
	}else
	if(b[2]=='B'&&d[2]=='C'){
		cout<<"1";
	}else
	if(b[2]=='F'&&d[2]=='G'){
		cout<<"1";
	}else
	if(b[2]=='B'&&d[2]=='A'){
		cout<<"1";
	}else
	if(b[2]=='C'&&d[2]=='B'){
		cout<<"1";
	}else
	if(b[2]=='G'&&d[2]=='F'){
		cout<<"1";
	}else
	cout<<"0";
	return 0;
}
