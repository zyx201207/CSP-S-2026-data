//GZ-J00255 ºÎÐÒ¶ù
#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int f=0,f2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<"1";
		if(a2[0]==b2[0]&&a2[1]==b2[1]){
			cout<<"1";
				if(a2[2]=='A'){
				if(b2[2]=='B'||b2[2]=='C'){
					cout<<1;
					f=1;
				} 		
			}
			else if(a2[2]=='B'){
				if(b2[2]=='A'||b2[2]=='C'){
					cout<<1;
					f=1;
				} 
			}
			else if(a2[2]=='C'){
				if(b2[2]=='A'||b2[2]=='B'){
					cout<<1;
					f=1;
				} 
			}
			else if(a2[2]=='D'){
				if(b2[2]='F'){
					cout<<1;
					f=1;
				} 
			}
			else if(a2[2]=='F'){
				if(b2[2]=='D') {
					cout<<1;
					f=1;
				}
			}	
			if(f==0){
				cout<<"00";
				return 0;
			}
			if(a2[2]=='A'){
				if(b2[2]=='B'){
					cout<<1;
					f2=1;
				} 		
			}
			else if(a2[2]=='B'){
				if(b2[2]=='A'||b2[2]=='C'){
					cout<<1;
					f2=1;
				} 
			}
			else if(a2[2]=='C'){
				if(b2[2]=='B'){
					cout<<1;
					f2=1;
				} 
			}
			else if(a2[2]=='D'){
				if(b2[2]='F'){
					cout<<1;
					f2=1;
				} 
			}
			else if(a2[2]=='F'){
				if(b2[2]=='D') {
					cout<<1;
					f2=1;
				}
			}	
			if(f2==0) cout<<0;
		}
		else cout<<"000";
	} 
	else cout<<"0000";
	return 0;
}
