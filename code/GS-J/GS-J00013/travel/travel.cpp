#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string a=s1.substr(0,2);
		string b=s2.substr(0,2);
		if(a==b){
			cout<<1;
			char c=s1[2];
			char d=s2[2];
			if('A'<=c&&c<='C'&&'A'<=d&&d<='C'||'D'<=c&&c<='E'&&'D'<=d&&d<='E'){
				cout<<1;
				if(abs(c-d)==1){
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
