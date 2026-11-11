#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s,s1,a,a1;
    cin>>s>>s1>>a>>a1;
    if(s==a){
	    cout <<1;	
	}
	else{
	    cout <<"0000";
	    return 0;	
	}
	if(s1[1]==a1[1]&&s1[0]==a1[0]){
		cout <<1;
    }
    else{
	    cout<<"000";
	    return 0;   
	}
	if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(a1[2]=='A'||a1[2]=='B'||a1[2]=='C'))||((s1[2]=='D'||s1[2]=='E')&&(a1[2]=='D'||a1[2]=='E'))){
		cout <<1;
	}
	else{
		cout <<"00";
		return 0;
	}
	if((s1[2]=='A'&&a1[2]=='B')||(a1[2]=='A'&&s1[2]=='B')||(s1[2]=='C'&&a1[2]=='D')||(s1[2]=='D'&&a1[2]=='C')||(a1[2]=='D'&&s1[2]=='E')||(a1[2]=='E'&&s1[2]=='D')){
		cout <<1;
	}
	else{
		cout <<0;
	}
    return 0;
}
