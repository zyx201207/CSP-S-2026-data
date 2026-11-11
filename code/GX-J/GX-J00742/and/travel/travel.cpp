#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	string s1;
	string s2;
	string s3;
	cin>>s>>s1>>s2>>s3;
	if(s!=s2){
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	if(s1[0]==s3[0]&&s1[1]==s3[1]){
		cout<<"1";
		}
		else {
			cout<<"000";
			return 0;
			}
			if(s1[2]<='C'&&s1[2]>='A'&&s3[2]<='C'&&s3[2]>='A'){
				cout<<"1";
			}
			else if(s1[2]<='F'&&s1[2]>='D'&&s3[2]<='F'&&s3[2]>='D'){
				cout<<"1";
			}
			else{
				cout<<"00";
				return 0;
			}
			if(s1[2]+1==s3[2]||s1[2]-1==s3[2]||s1[2]+2==s3[2]||s1[2]-2==s3[2]){
				cout<<"1";
			}
			else cout<<0;
	return 0;
	}
