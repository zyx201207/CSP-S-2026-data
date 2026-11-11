#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	char s1,s2;
	int a,b;
	cin>>c1>>a>>s1>>c2>>b>>s1;
	if(c1==c2){
		cout<<"1";
			if(a==b){
			cout<<"1";
				if(s1=='A'||s1=='B'||s1=='C'&&s2=='A'||s2=='B'||s1=='C'){
					cout<<"1";
					if(s1=='B'||s2=='B') cout<<"1";
					else cout<<"0";
				}
					else if((s1=='D'||s1=='F')&&(s2=='D'||s2=='F')){
						cout<<"11";
					}
					 else cout<<"00";
			}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
