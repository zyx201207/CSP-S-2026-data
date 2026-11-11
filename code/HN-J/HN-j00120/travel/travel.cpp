#include<bits/stdc++.h> 
using namespace std;
long long c1,s1,c2,s2;
char ss1,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>ss1>>c2>>s2>>ss2;
	if(c1==c2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if(((ss1=='A'||ss1=='B'||ss1=='C')&&(ss2=='A'||ss2=='B'||ss2=='C'))||((ss1=='D'||ss1=='F')&&(ss2=='D'||ss2=='F'))){
				cout<<1;
				if((ss1=='A'&&ss2=='B')||(ss1=='B'&&(ss2=='A'||ss2=='C'))||(ss1=='C'&&ss2=='B')||(ss1=='D'&&ss2=='F')||(ss1=='F'&&ss2=='D')){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	return 0;
}
