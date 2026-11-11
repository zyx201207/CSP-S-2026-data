#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","m",stdout);
    string c1,s1,c2,s2;
    cin >>c1>>s1>>c2>>s2;
    string z=0;
    if(c1==c2){
        z+='1';
    }else{
        z+='0';
    }
    if(s1[0]+s1[1]==s2[0]+s2[1]){
		z+='1';
    }else{
		z+='0';
    }
    if(s1[2]==s2[2]+1||s1[2]==s2[2]+2||s1[2]==s2[2]-1||s1[2]==s2[2]-2){
		z+='1';
    }else{
        z+='0';
    }
    if(s1[2]-1||s1[2]+1==s2[2]){
		z+='1';
    }else{
		z+='0';
    }
    cout <<z;
    return 0;
}
