#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1;
    cin>>c2>>s2;
    string n="0000";
    if(c1!=c2){
        n[0]='0';
    }else{
        n[0]='1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            n[1]='1';
            if((abs((int)s1[2]-s2[2])<=2)&&(s1[2]!='D')&&(s2[2]!='D')||(s1[2]=='D')&&(s2[2]=='F')||(s1[2]=='F')&&(s2[2]=='D')){
                n[2]='1';
                if((abs((int)s1[2]-s2[2])<2)&&(s1[2]!='D')&&(s2[2]!='D')||(s1[2]=='D')&&(s2[2]=='F')||(s1[2]=='F')&&(s2[2]=='D')){
                    n[3]='1';
                }
            }
        }
    }
    cout<<n;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
