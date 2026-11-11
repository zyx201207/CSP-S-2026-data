#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    char c1=s2[2],c2=s4[2];
    if(s1==s3){
        cout<<"1";
        if(s2[0]==s4[0] && s2[1]==s4[1]){
            cout<<"1";
            if((c1<'D' && c2<'D') || (c1>='D' && c2>='D')){
                cout<<"1";
                int k=c1-c2;
                if(k==1 || k==-1){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
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
