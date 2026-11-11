#include<bits/stdc++.h>
using namespace std;
struct ticket{
	string c;
	string s;
}t[3];
bool isSame(string a,string b){
	if((a[2]=='A'||'B'||'C')&&(b[2]=='A'||'B'||'C')){
		return true;
	}
	if((a[2]=='D'||'F')&&(b[2]=='D'||'F')){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","out",stdout);
	for(int i=0;i<2;i++){
		cin>>t[i].c>>t[i].s;
	}
	string a="0000";
	if(t[0].c==t[1].c){
		a[0]='1';
		if(t[0].s[0]==t[1].s[0]&&t[0].s[1]==t[1].s[1]){
			a[1]='1';
			if(t[0].s[2]=='A'&& t[1].s[2]=='B' || t[0].s[2]=='B'&& t[1].s[2]=='A'){
				a[2]='1';
		        a[3]='1';
	        }else if(t[0].s[2]=='B'&&t[1].s[2]=='C' || t[0].s[2]=='C'&& t[1].s[2]=='B'){
	        	a[2]='1';
		        a[3]='1';
 	        }else if(t[0].s[2]=='D'&&t[1].s[2]=='F' || t[0].s[2]=='F'&& t[1].s[2]=='D'){
 	        	a[2]='1';
		        a[3]='1';
	        }else if(t[0].s[2]=='A'&&t[1].s[2]=='C' || t[0].s[2]=='C'&& t[1].s[2]=='A'){
	        	a[2]='1';
	        	a[3]='0';
			}else{
				a[2]='0';
	            a[3]='0';
			}
		}else{
			a[1]='0';
			a[2]='0';
			a[3]='0';
		}
	}else{
		a[0]='0';
		a[1]='0';
		a[2]='0';
		a[3]='0';
	}
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
	return 0;
}
