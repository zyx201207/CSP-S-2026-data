#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
		int a=s2[0]-'0',b=s2[1]-'0',c=s4[0]-'0',d=s4[1]-'0';
		char e=s2[2],f=s4[2];
		if(a==c&&b==d){
			cout<<1;
			if(((e=='A'||e=='B'||e=='C')&&(f=='A'||f=='B'||f=='C'))||((e=='D'||e=='F')&&(f=='D'||f=='F'))){
				cout<<1;
				if((e=='D'||e=='F')&&(f=='D'||f=='F')){
					cout<<1;
				}else if(e+1==f||f+1==e){
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
	return 0;
}
