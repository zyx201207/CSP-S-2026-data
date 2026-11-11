#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in",'r',stdin);
    freopen("travel.out",'w',stdout);
    string a1,a2,s1,s2;
    cin>>a1>>a2>>s1>>s2;
    string q="";
    if(a1==s1){
        q+='1';
        if(s2[0]+s2[1]==a2[0]+a2[1]){
            q+='1';
            if(a2[2]>='A' && a2[2]<='C' && s2[2]>='A' && s2[2]<='C'){
                q+='1';
                if(a2[2]=='A' && s2[2]=='B'){
                    q+='1';
                }
                else if(a2[2]=='C' && s2[2]=='B'){
                    q+='1';
                }
                else if(a2[2]=='B' && s2[2]=='A'){
                    q+='1';
                }
                else if(a2[2]=='B' && s2[2]=='C'){
                    q+='1';
                }
                else{
                    q+='0';
                }
            }
            else if(a2[2]>='D' && a2[2]<='F' && s2[2]>='D' && s2[2]<='F'){
                q+='1';
                if(a2[2]=='D' && s2[2]=='F'){
                    q+='1';
                }
                else if(a2[2]=='F' && s2[2]=='D'){
                    q+='1';
                }
                else{
                    q+='0';
                }
            }
            else{
                q+="00";
            }
        }
        else{
            q+="000";
        }
    }
    else{
        q+="0000";
    }
    cout<<q;
    return 0;
}