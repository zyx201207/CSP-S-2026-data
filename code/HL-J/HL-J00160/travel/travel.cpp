#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    short s=0;
    if(c1==c2){
        s+=1000;
        if(s1[1]==s2[1]&&s1[0]==s2[0]){
            s+=100;
            if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='A'&&s2[2]=='C'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='F'&&s2[2]=='D'){
                s+=10;
                if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='A'){
                    s+=0;
                }else{
                    s++;
                }
            }
        }
        cout<<s;
    }else{
        cout<<"0000";
    }

    return 0;
}
