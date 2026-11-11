/*
in:
02 01A 02 01B

02 01C 02 01A

02 01C 02 01D

02 02B 02 01A

02 01A 03 01A
out:
1111

1110

1100

1000

0000
*/
#include<bits/stdc++.h>
using namespace std;

int c1,c2;

string s1,s2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
    }else{
        cout<<'1';
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<'1';
            if(s1[2]=='A'){
                if(s2[2]=='B'){
                    cout<<"11";
                }else if(s2[2]=='C'){
                    cout<<"10";
                }else{
                    cout<<"00";
                }
            }else if(s1[2]=='B'){
                if(s2[2]=='A'||s2[2]=='C'){
                    cout<<"11";
                }else{
                    cout<<"00";
                }
            }else if(s1[2]=='C'){
                if(s2[2]=='A'){
                    cout<<"10";
                }else if(s2[2]=='B'){
                    cout<<"11";
                }else{
                    cout<<"00";
                }
            }else if(s1[2]=='D'){
                if(s2[2]=='F'){
                    cout<<"11";
                }else{
                    cout<<"00";
                }
            }else{
                if(s2[2]=='D'){
                    cout<<"11";
                }else{
                    cout<<"00";
                }
            }
        }else{
            cout<<"000";
        }
    }
    return 0;
}
