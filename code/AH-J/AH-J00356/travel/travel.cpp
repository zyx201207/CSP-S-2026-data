#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	a=(s1[0]-'0')+(s1[1]-'0');
	b=(s2[0]-'0')+(s2[1]-'0');
	c=s1[2]-'0';
	d=s2[2]-'0';
	if(c1==c2){
		cout<<"1";
		if(a==b){
			cout<<"1";
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					cout<<"1";
					if(abs(c-d)==1){
						cout<<"1";
					}else{
						cout<<"0";
						return 0;
					}
				}else{
					cout<<"00";
					return 0;
				}
			}else if(s1[2]=='D'||s1[2]=='F'){
				if(s2[2]=='D'||s2[2]=='F'){
					cout<<"1";
					if(abs(c-d)==1){
						cout<<"1";
					}else{
						cout<<"0";
						return 0;
					}
				}else{
					cout<<"00";
					return 0;
				}
			}
		}else{
			cout<<"000";
			return 0;
		}
		
	}else{
		cout<<"0000";
	}
	
	return 0;
} 
