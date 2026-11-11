#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	a=((s1[0]-'0')*10+s1[1]-'0');
	b=((s2[0]-'0')*10+s2[1]-'0');
	int f=0;
	if(c1==c2){
		cout<<1;
		if(a==b){
			cout<<1;
			if(((s1[2]=='F'||s1[2]=='D')&&(s2[2]=='F'||s2[2]=='D'))||((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))){
				cout<<1;
				
				if(s1[2]=='A'){
					if(s2[2]=='B'){
						cout<<1;
						f=1;
					}
				}else if(s1[2]=='B'){
					if(s2[2]=='A'){
						cout<<1;
						f=1;
					}
					else if(s2[2]=='C'){
						cout<<1;
						f=1;
					}
				}else if(s1[2]=='C'){
					if(s2[2]=='B'){
						cout<<1;
						f=1;
					}
				}else if(s1[2]=='D'){
					if(s2[2]=='F'){
						cout<<1;
						f=1;
					}
				}else if(s1[2]=='E'){
					if(s2[2]=='D'){
						cout<<1;
						f=1;
					}
				}
				if(f==0){
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
