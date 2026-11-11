#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string s;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        s+='1';
    }
    else{
        s+='0';
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]&&c1[0]==c2[0]&&c1[1]==c2[1]){
        s+='1';
        if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
            s+='1';
        }
        else{
            s+='0';
        }
    }
    else{
        s=s+'0'+'0';
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        if(s1[2]==s2[2]+1||s1[2]+1==s2[2]){
            if(s2[2]=='C'&&s1[2]=='D'||s2[2]=='D'&&s1[2]=='C'){
                s+='0';
            }
            else{
                s+='1';
            }
        }
        else{
            s+='0';
        }
    }
    else{
        s+='0';
    }
    cout<<s;
    return 0;
}
/*
02 01A 02 01B
*/
