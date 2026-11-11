#include<bits/stdc++.h>
using namespace std;
int main(){
	int c,s,cc,ss;
	string c1,s1,c2,s2;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<=1;i++){
		s=s1[i]-'0';
	}
	for(int i=0;i<=1;i++){
		ss=s2[i]-'0';
	}
	if(s==ss){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
		if(s1[3]=='A'){
			if(s2[3]=='B'||s2[3]=='C'){
				cout<<"1";
				if(s2[3]=='B'){
					cout<<"1";
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}
		else if(s1[3]=='B'){
			if(s2[3]=='A'||s2[3]=='C'){
				cout<<"11";
				return 0;
			}else{
				cout<<"00";
				return 0;
			}
		}
		else if(s1[3]=='C'){
			if(s2[3]=='A'||s2[3]=='B'){
				cout<<"1";
				if(s2[3]=='B'){
					cout<<"1";
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}
		else if(s1[3]=='D'){
			if(s2[3]=='F'){
				cout<<"11";
				return 0;
			}else{
				cout<<"00";
				return 0;
			}
		}
		cout<<"00";
	return 0;
	
} 
