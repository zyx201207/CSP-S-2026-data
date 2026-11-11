#include<bits/stdc++.h>
using namespace std;
long long c1a,c1b,c1c,c2a,c2b,c2c;
char s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1a>>c1b>>s1>>c2a>>c2b>>s2;
	if(s1=='A'||s1=='B'||s1=='C'){
		c1c=1;
	}else{
		c1c=2;
	}
	if(s2=='A'||s2=='B'||s2=='C'){
		c2c=1;
	}else{
		c2c=2;
	}
	if(c1a!=c2a){
		cout<<"0000";
	}else{
		if(c1b!=c2b){
			cout<<"1000";
		}else{
			if(c1c!=c2c){
				cout<<"1100";
			}else{
				if(abs((int)s1-s2)>1){
					cout<<"1110";
				}else{
					cout<<"1111";
				}
			}
		}
	}
	return 0;
}
