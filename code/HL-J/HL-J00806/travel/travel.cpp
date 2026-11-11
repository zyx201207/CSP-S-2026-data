#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
    string s1,s2,s11,s22;
    cin>>s1>>s11>>s2>>s22;
    if(s1==s2){
    	cout<<1;
    	if(s11[0]==s22[0] && s11[1]==s22[1]){
    		cout<<1;
    		if (s11[2]=='A' or s11[2]=='B'  or s11[2]=='C'){
    			if (s22[2]=='A' || s22[2]=='B' ||s22[2]=='C' ){
    				cout<<1;
    				if(s11[2]=='A' ){
    					if(s22[2]=='B'){
    						cout<<1;
						}
						else{
							cout<<0;
						}
					}
					else if(s11[2]=='B'){
						cout<<1;
					}
					else if(s11[2]=='C'){
						if(s22[2]=='B'){
							cout<<1;
						}
						else{
							cout<<0;
						}
					}
				}
				else{
					cout<<"00";
				}
			}
			else if(s11[2]=='D' || s11[2]=='F'){
				if(s22[2]=='D' || s22[2]=='F'){
					cout<<"11";
				}
				else{
					cout<<"00";
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
