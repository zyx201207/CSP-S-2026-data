#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int check(string a1){
	int x;
	if(a1[2]=='A'||a1[2]=='B'||a1[2]=='C'){
		x=0;
	}else if(a1[2]=='D'||a1[2]=='F'){
		x=1;
	}
	return x;
}
bool f(string a1,string a2,int t){
	if(t==0){
		if((a1[2]=='A'&&a2[2]=='B')||(a2[2]=='A'&&a1[2]=='B'))return true;
		if((a1[2]=='B'&&a2[2]=='C')||(a2[2]=='B'&&a1[2]=='C'))return true;
	}else if(t==1){
		if((a1[2]=='D'&&a2[2]=='F')||(a2[2]=='D'&&a1[2]=='F'))return true;
	}
	return false;
}
int main(){
	cin>>c>>s>>cc>>ss;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	if(c==cc){
		cout<<1;
		if(s.substr(0,2)==ss.substr(0,2)){
			cout<<1;
			int tt=check(s);
			if(check(s)==check(ss)){
				cout<<1;
				if(f(s,ss,tt)){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
		
	}else{
		cout<<"0000";
	}
//	cout<<c.substr(0,2);
	return 0;
}
