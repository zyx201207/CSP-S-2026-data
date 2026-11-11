#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
		int a=(s2[0]-'0')*10+(s2[1]-'0');
		int b=(s4[0]-'0')*10+(s4[1]-'0');
		if(a==b){
			cout<<1;
			char c=s2[2];
			char d=s4[2];
			if((c>='A'&&c<='C')&&(d>='A'&&d<='C')){
				cout<<1;
				if(c=='A'||c=='C'){
					if(d=='B') {
						cout<<1;
						return 0;
					} 	
					cout<<0;
					return 0;
				}
				if(c=='B'){
					if(d=='C'||d=='A') {
						cout<<1;
						return 0;
					} 	
					cout<<0;
					return 0;
				}
			}else if((c>='D'&&c<='F')&&(d>='D'&&d<='F')){
				cout<<"11";
			}else {
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


