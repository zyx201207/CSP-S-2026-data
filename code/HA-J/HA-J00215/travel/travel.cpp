#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<1;
		if(c2[01]==s2[01]){
		    cout<<1;}
	    else{
		    cout<<"000";}
	    if(c2[2]=='C'&&s2[2]=='D'){
		    cout<<"00";}
	    else if(c2[2]=='D'&&s2[2]=='C'){
		    cout<<"00";}
	    else{
		    cout<<1;
	        if(c2[2]==s2[2]+1||c2[2]==s2[2]-1){
		        cout<<1;
	}
	        else if(c2[2]=='C'&&s2[2]=='D'){
		        cout<<0;
	}
	        else if(c2[2]=='D'&&s2[2]=='C'){
		        cout<<0;}
            else {
		        cout<<0;}}
	}
	else{
		cout<<"0000";}
	
	return 0;
}
