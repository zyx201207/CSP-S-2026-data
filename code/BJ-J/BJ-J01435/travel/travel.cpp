#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool q1,q2,q3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        q1=1;
    }else{
        cout<<0;
    }
    if(q1==1&&s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<1;
        q2=1;
    }else{
        cout<<0;
    }
    if(q2==1){
        if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'){
            cout<<1;
            q3=1;
        }else{
            cout<<0;
        }
    }else{
        cout<<0;
    }
    if(q3==1){
        if(s1[2]>'C'&&s2[2]>'C'){
            cout<<1;
        }else if(abs(int(s1[2])-int(s2[2]))==1){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        cout<<0;
    }
    return 0;
}
