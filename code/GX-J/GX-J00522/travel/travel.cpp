#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a[5],b[5];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	a[1]=s1[0]-'0';
	a[2]=s1[1]-'0';
	b[1]=s3[0]-'0';
	b[2]=s3[1]-'0';
	if(a[2]==b[2]){
		cout<<1;
		if(s2[1]==s4[1]&&s2[0]==s4[0]){
			cout<<1;
			if ( ( ( s2[2]>='A' && s2[2]<='C' ) && ( s4[2]<='C' && s4[2]>='A') ) || ( ( s2[2]>='D' && s2[2]<='F' ) && ( s4[2]<='D' && s4[2]>='F') ) ){
				cout<<1;
				if( abs ( s2[2] - s4[2] ) == 1 ){
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
