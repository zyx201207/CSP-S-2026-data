#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s;
    string s1;
    string s2;
    string s3;
    cin>>s>>s1>>s2>>s3;
    int s11,s31,m;
    s11=(s1[0]-'0')*10+(s1[1]-'0');
    s31=(s3[0]-'0')*10+(s3[1]-'0');
    int s12=s1[2]-'A';
    int s32=s3[2]-'A';
    if(s12==3){
        s12++;
    }
    if(s32==3){
        s32++;
    }
    if(s12<s32){
        swap(s12,s32);
    }
    if(s32<=2&&(s12>2&&s12<=5)){
        s12+=99;
    }
    m=s12-s32;
    if(s==s2){
        cout<<"1";
        if(s11==s31){
            cout<<"1";
            if(m<=2){
                cout<<"1";
                if(m==1){
                    cout<<"1";
                }else{
                    cout<<"0";
                    return 0;
                }
            }else{
                cout<<"00";
                return 0;
            }
        }else{
            cout<<"000";
            return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }

    return 0;
}
