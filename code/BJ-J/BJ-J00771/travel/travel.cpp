#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
bool check(){
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
        return s2[2]=='A'||s2[2]=='B'||s2[2]=='C';
    }else{
        return s2[2]=='D'||s2[2]=='F';
    }
}
bool check2(){
    if(s1[2]=='A')return s2[2]=='B';
    else if(s1[2]=='B')return s2[2]=='A'||s2[2]=='C';
    else if(s1[2]=='C')return s2[2]=='B';
    else if(s1[2]=='D')return s2[2]=='F';
    else return s2[2]=='D';
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);/*zhushi!!!!!!!!*/
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if(check()){
                cout<<1;
                if(check2()){
                    cout<<1;
                }else cout<<"0";
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }


    return 0;
}
