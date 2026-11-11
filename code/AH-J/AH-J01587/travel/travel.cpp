#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char bb,dd;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>bb>>c>>d>>dd;
	if(a==c){
	    cout<<"1";
		if(b==d){
			cout<<"1";
			if(bb=='A'||bb=='B'||bb=='C'){
			    if(dd=='F'||dd=='D') cout<<"00";
			    if(dd=='A'||dd=='B'||dd=='C'){
			   	    if(abs(bb-dd)==1){
			   	    	cout<<"11";
					}
					else cout<<"10";
			   }	
			}
			else if(dd=='F'||dd=='D'){
					cout<<"11";
			}
		}
		else cout<<"000";
        
	}
	else{
		cout<<"0000";
	}
	return 0;
}
