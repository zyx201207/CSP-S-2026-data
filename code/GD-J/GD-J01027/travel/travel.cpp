#include <bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
long long t1,t2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a1>>b1>>a2>>b2;
    s1=(a1[0]-'0')*10+(a1[1]-'0');
    s2=(a2[0]-'0')*10+(a2[1]-'0');
	if(s1==s2){
		cout<<"1";
		t1=(b1[0]-'0')*10+(b1[1]-'0');
		t2=(b2[0]-'0')*10+(b2[1]-'0');
		if(t1==t2){
			cout<<"1";
			if(b1[2]>='A' && b1[2]<='C' && b2[2]>='A' && b2[2]<='C'){
				cout<<"1";
				if((b1[2]=='A' && b2[2]=='B') || (b1[2]=='B' && b2[2]=='A') || (b1[2]=='B' && b2[2]=='C') || (b1[2]=='C' && b2[2]=='B')){
					cout<<"1";
				}else cout<<"0";
			}else if((b1[2]=='D' && b2[2]=='F') || (b1[2]=='F' && b2[2]=='C')) cout<<"11";
			else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	
	return 0;
}

