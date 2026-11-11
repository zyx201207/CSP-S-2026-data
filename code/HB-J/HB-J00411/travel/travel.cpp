#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,da;
char a1,a2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        da+='1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            da+='1';
            if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
                da+="11";
            }else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')){
                da+='1';
                if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')){
                    da+='1';
                }else da+='0';
            }else da+="00";
        }else da+="000";
    }else da+="0000";
    cout<<da;
    return 0;
}
/*
02 01A 02 01B
02 01C 02 01A
02 01C 02 01D
*/
