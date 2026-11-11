#include<bits/stdc++.h>
using namespace std;
int same(string s1,string s2){
    if(s1==s2)return 1;
    return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int s1,s3;
    string s4,s2;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        cout<<1;
        string s02="",s04="";
        for(int i=0;i<2;i++){
            s02+=s2[i];
            s04+=s4[i];
        }
        if(same(s02,s04)){
            cout<<1;
            if(s2[2]<'D' && s4[2]>='D' || s2[2]>='D' && s4[2]<'D'){
                cout<<"00";
            }else{
                cout<<1;
                if(abs(s2[2]-s4[2])==1){
                    cout<<1;
                }else cout<<0;
            }
        }else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
