#include<iostream>
#include<string>
using namespace.std;
int main(){
    string c,s,c1,s1;
    int a,b,c,d;
    cin>>c>>s>>c1>>s1;
    if(c==c1){
        a=1;
        if(s[0]==s1[0]&&s[1]==s1[1]){
            b=1;
            if(s[2]=='A'||s[2]=='B'||s[2]=='C'){
                if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
                    c=1;
                    if(s[2]+1==s1[2]||s[2]-1==s1[2])
                        d=1;
                }
             if(s[2]=='F'||s[2]=='D'){
                if(s1[2]=='F'||s1[2]=='D'){
                    c=1;
                    if(s[2]+1==s1[2]||s[2]-1==s1[2])
                        d=1;
                }
            }
        }
    }
    if(a==1)
    cout<<"1";
    else
    cout<<"0";
    if(b==1)
    cout<<"1";
    else
    cout<<"0";
    if(c==1)
    cout<<"1";
    else
    cout<<"0";
    if(d==1)
    cout<<"1";
    else
    cout<<"0";
return 0;
}
