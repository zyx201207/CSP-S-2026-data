#include<bits/stdc++.h>
using namespace std ;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1 , s1 , c2 , s2 ;
    bool t = false ;
    cin >> c1 >> s1 >> c2 >> s2 ;
    string s ;
    if(c1 == c2){
        s += '1' ;
            if(s1[0] == s2[0] && s1[1] == s2[1]){
                s += '1';
                if((int)s1[2] >= (int)'A' && (int)s1[2] <= (int)'C'){
                    if((int)s2[2] >= (int)'A' && (int)s2[2] <= (int)'C'){
                        s += '1';
                        t = true ;
                    }
                }else if(s1[2]=='D'||s1[2] == 'F'){
                    if(s2[2]=='D'||s2[2] == 'F'){
                        s += '1';
                        t = true;
                    }
                }else{
                    s += "00";
                }
            }else{
                s += "000";
            }
            }else{
                s +="0000";
            }

     if((s1[2]-s2[2] == 1) || (s1[2]-s2[2] == -1) && t){
            s += '1' ;
        }else if(t){
            s += '0' ;
        }
    cout << s <<' ';
    return 0 ;
}
