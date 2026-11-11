#include<bits/stdc++.h>
using namespace std;
string s;
string s1;
string s2;
string s3;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>s2>>s3;
	if(s==s2){
		if(s1[0]==s3[0] && s1[1]==s3[1]){
			if(s1[2]=='A' && s3[2]=='B'){
				cout<<"1111"<<'\n';
			}
			else if(s1[2]=='B' && s3[2]=='C'){
				cout<<"1111"<<'\n';
			}
			else if(s1[2]=='B' && s3[2]=='A'){
				cout<<"1111"<<'\n';
			}
			else if(s1[2]=='C' && s3[2]=='B'){
				cout<<"1111"<<'\n';
			}
			else if(s1[2]=='D' && s3[2]=='E'){
				cout<<"1111"<<'\n';
			}
			else if(s1[2]=='E' && s3[2]=='D'){
				cout<<"1111"<<'\n';
			}
			else{
				if(s1[2]=='A' && s3[2]=='C'){
					cout<<"1110"<<'\n';
				}
				else if(s1[2]=='C' && s3[2]=='A'){
					cout<<"1110"<<'\n';
				}
				else{
					cout<<"1100"<<'\n';
				}
				
			}
		}
		else cout<<"1000"<<'\n';
	}
	else cout<<"0000"<<'\n';
	return 0;
}
