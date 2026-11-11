#include<bits/stdc++.h>
using namespace std;
string r,x;
int s,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>r>>s2>>x;
	bool f=1;
	if(s!=s2){
		f=0;
		cout<<"0000";
	}
	if(f==1){
		cout<<"1";
		if(r[0]==x[0]&&r[1]==x[1]){
			cout<<"1";
			if((r[2]<='C'&&x[2]<='C')||(r[2]=='D'&&x[2]=='F')||(r[2]=='F'&&x[2]=='D')){
				cout<<"1";
				if((r[2]=='D'&&x[2]=='F')||(r[2]=='A'&&x[2]=='B')||(r[2]=='B'&&x[2]=='C')||(r[2]=='F'&&x[2]=='D')||(r[2]=='B'&&x[2]=='A')||(r[2]=='C'&&x[2]=='B')){
					cout<<"1";
				
				}else{
				cout<<"0";
				}
			}else{
			cout<<"00";
			}
		}else{
			cout<<"000";
		}
		
		
	}
	
	
	return 0;
}
