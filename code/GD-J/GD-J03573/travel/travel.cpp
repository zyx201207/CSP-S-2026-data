#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		if(s1.substr(0,2)!=s2.substr(0,2)){
			cout<<"000";
		}
		else{
			cout<<"1";
			char a=s1[2],b=s2[2];
			if(a<='C'&&b<='C'){
				cout<<"1";
				if(a-b==-1||a-b==1){
					cout<<"1";
				}
				else cout<<"0";
			}
			else if(a>'C'&&b>'C'){
				cout<<"11";
			}
			else{
				cout<<"00";
			}
		}
	}
} 
