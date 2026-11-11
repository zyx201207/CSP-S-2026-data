#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	string p1=s1.substr(0,2);
    string p2=s2.substr(0,2);
    char a=s1[2],b=s2[2];
    if(c1==c2){
    	cout<<1;
    	if(p1==p2){
    		cout<<1;
    		if((a=='D'||a=='F')&&(b=='A'||b=='B'||b=='C')){
    			cout<<"00";
			}else if((b=='D'||b=='F')&&(a=='A'||a=='B'||a=='C')){
				cout<<"00";
			}else{
				cout<<1;
				if(abs(a-b)==1){
					cout<<1;
				}else{
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
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
