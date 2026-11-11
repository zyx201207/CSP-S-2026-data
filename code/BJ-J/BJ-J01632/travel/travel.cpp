#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,s11,s21;
    char s12,s22;
    cin>>c1>>s1>>c2>>s2;
    s11=s1[0]+s1[1];
    s21=s2[0]+s2[1];
    s12=s1[2];
    s22=s2[2];
    if(c1==c2){
        cout<<1;
        if(s11==s21){
            cout<<1;
            if(((s12=='A'||s12=='B'||s12=='C')&&(s22=='D'||s22=='F'))||((s22=='A'||s22=='B'||s22=='C')&&(s12=='D'||s12=='F'))){
                cout<<"00";
                return 0;
            }
            else{
                cout<<1;
                if(s12>s22){
                    if(s12-s22==1){
                        cout<<1;
                    }
                    else{
                        cout<<0;
                    }
                }
                else{
                    if(s22-s12==1){
                        cout<<1;
                    }
                    else{
                        cout<<0;
                    }
                }
            }
        }
        else{
            cout<<"000";
            return 0;
        }
    }
    else{
       cout<<"0000";
    }
    return 0;
}