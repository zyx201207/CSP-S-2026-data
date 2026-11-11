#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int s[100],s2[100];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}
    
	
	if(a==c){
		
		if(b[0]-'0'==d[0]-'0'&&b[1]-'0'==d[1]-'0'){
			if(((b[2]-'A')-(d[2]-'A')==1)||((d[2]-'A')-(b[2]-'A')==1)||((b[2]-'A')-(d[2]-'A')==2)||((d[2]-'A')-(b[2]-'A')==2)){
				if((d[2]=='D'||b[2]=='D')&&((d[2]=='C'||b[2]=='C'))){
					cout<<1100;
					return 0;
                }
				if((b[2]-d[2]==1)||(d[2]-b[2]==1)){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}
	return 0;
}
