#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string a,b;
	a+=s1[0];
	a+=s1[1];
	b+=s2[0];
	b+=s2[1];
	if(c1==c2){
		cout<<"1";
		if(a==b){
			cout<<"1";
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
				cout<<"1";
				if(abs(s1[2]-s2[2])==1){
					cout<<"1";
				}
				else cout<<"0";
			}
			else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
				cout<<"11";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
