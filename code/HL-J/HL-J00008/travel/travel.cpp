#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;

bool is_tp(string a,string b){
	if(a[0]==b[0]&&a[1]==b[1]){
		return true;
	}else{
		return false;
	}
}

bool is_tc(string a,string b){
	if(!is_tp(a,b)){
		return false;
	}
	if(((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C'))||((a[2]=='D'||a[2]=='F'))){
		return true;
	}else{
		return false;
	}
}

bool is_xl(string a,string b){
	if(!is_tp(a,b)){
		return false;
	}
	if((a[2]=='C'&&b[2]=='D')||(b[2]=='C'&&a[2]=='D')){
		return false;
	}
	if(a[2]+1==b[2]||a[2]-1==b[2]||b[2]+1==a[2]||b[2]-1==a[2]&&is_tc(a,b)){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}else{
		cout<<'1';
	}
	
	if(is_tp(s1,s2)){
		cout<<'1';
	}else{
		cout<<'0';
	}
	
	if(is_tc(s1,s2)){
		cout<<'1';
	}else{
		cout<<'0';
	}
	
	if(is_xl(s1,s2)){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
}
