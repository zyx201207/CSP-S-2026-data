#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        cout<<1;
        int R_cnt=(s2[0]-'0')*10+(s2[1]-'0');
        int X_cnt=(s4[0]-'0')*10+(s4[1]-'0');
        char R_c=s2[2],X_c=s4[2];
        if(R_cnt==X_cnt){
            cout<<1;
            if(R_c<='C'&&X_c<='C'){
                cout<<1;
                if(R_c=='A'&&X_c=='B'||R_c=='B'&&X_c=='A')cout<<1;
                else if(R_c=='B'&&X_c=='C'||R_c=='C'&&X_c=='B')cout<<1;
                else cout<<0;
            }
            else if(R_c>='D'&&X_c>='D'){
                cout<<1;
                if(R_c=='D'&&X_c=='F'||R_c=='F'&&X_c=='D')cout<<1;
                else cout<<0;
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
