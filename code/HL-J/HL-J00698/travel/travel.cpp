#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s2; 
    int s1;
	cin>>s1>>s2;
    int t1;
	string t2; 
	cin>>t1>>t2;
	
    if(s1==t1) cout<<"1";
    else{
    	cout<<"0000";
    	return 0;
	}
    
	for(int i=0; i<=1; i++){
		if(s2[i]!=t2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	    
    if((s2[2]<='C'&&t2[2]<='C')||(s2[2]>'C'&&t2[2]>'C')) cout<<"1";
    else{
    	cout<<"00";
    	return 0;
	}
    
    if((s2[2]+1==t2[2])||(s2[2]-1==t2[2])) cout<<"1";
    else cout<<"0";
    return 0;
}