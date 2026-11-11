#include<bits/stdc++.h>
using namespace std;
char s,t;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>s>>c>>d>>t;
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if(s=='A'||s=='B'||s=='C'){
				if(t=='A'||t=='B'||t=='C'){
					cout<<1;
					if(t==s+1||t==s-1){
						cout<<1;
					}
					else {
						cout<<0;
					}					
				}
				else{
					cout<<"00";
				}
			}
			else if(s=='D'||s=='E'){
				if(t=='D'||t=='E'){
					cout<<1;
					if(t==s+1||t==s-1){
						cout<<1;
					}
					else {
						cout<<0;
					}						
				}
				else{
					cout<<0;
				}
			}
		
		}
		else{
			cout<<"000";
		}		
	}
	else{
		cout<<"0000";
	}

	return 0;
}
