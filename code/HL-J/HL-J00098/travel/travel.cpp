#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3,f4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        f1 = true;
            if(s1[0]==s2[0]&&s1[1]==s2[1]){// tp
                f2 = true;
            if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
                f3 = true;
            }//tptc
            if(((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F'))||((s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D'))){
                f4 = true;
            }//xl
        }
    }

    if(f1==true){
        cout<<1;
    }
    else cout<<0;
    if(f2==true){
        cout<<1;
    }
    else cout<<0;
    if(f3==true){
        cout<<1;
    }
    else cout<<0;
    if(f4==true){
        cout<<1;
    }
    else cout<<0;
    return 0;
}
