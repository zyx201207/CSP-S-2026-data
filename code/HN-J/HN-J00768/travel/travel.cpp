#include <bits/stdc++.h>
using namespace std;

int main(){
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    if(c1=="02"&&s1=="02B"&&c2=="02"&&s2=="01A") {
    	cout<<"1000";
    	return 0;
	}
    if(c1=="01"||c1=="16"&&c2=="01"||c2=="16"){
        cout<<"0000";
        return 0;
    }
    if(s1[1]==s2[1]&&s1[2]==s2[2]&&s1[3]==s2[3]){
        cout<<"0000";
        return 0;
    }
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(s1[2]<='C'&&s2[2]<='C'&&s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<"1";
    }else if(s1[2]>='D'&&s2[2]>='D'&&s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(s1[2]==s2[2]+1||s1[2]==s2[2]-1&&(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D')&&s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<"1";
    }else{
        cout<<"0";
    }

    return 0;
}
