#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string c;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
     cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
       c+="1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            c+="1";
            if(s1[2]<='C'&&s2[2]<='C'){
                    c+="1";
                    if(s1[2]=='A'&&s2[2]=='B'){
                      c+="1";
                    }
                    else if(s1[2]=='B'&&s2[2]=='C'){
                        c+="1";
                    }
                    else if(s1[2]=='D'&&s2[2]=='F'){
                        c+="1";
                    }
                    else if(s1[2]=='B'&&s2[2]=='A'){
                       c+="1";
                    }
                    else if(s1[2]=='C'&&s2[2]=='B'){
                       c+="1";
                    }
                    else if(s1[2]=='F'&&s2[2]=='D'){
                       c+="1";
                    }
                    else c+="0";
            }
            else  c+="00";
        }
       else  c+="000";
    }
    else  c+="0000";
    cout<<c;
    return 0;
}
