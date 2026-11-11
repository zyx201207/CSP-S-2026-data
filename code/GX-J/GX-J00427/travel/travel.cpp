#include <bits/stdc++.h>
using namespace std;
int main(){
    int c1,c2,cnt=0;
    string s1,s2;
    freopen("travel.in","w",stdin);
    fread("travel.out","r",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=01 && c2!=01){
        if(c1!=16 && c2!=16){
            if(c1!=c2){
                cout<<"0";
                cnt+=1;
            }
            else{
                cout<<"1";
            }
        }
    }
    if(cnt==1){
        if(s1[0]!=s2[0]&&s1[1]!=s2[1]){
            cout<<"0";
            cnt+=1;
    }
}
    else{
        cout<<"1";
    }
    if(cnt==2){
        if(s1[2]<='C' && s2[2]<='C'){
            cout<<"1";
            cnt+=1;
        }
        else if(s1[2]>='D' && s2[2]>='D'){
            cout<<"1";
            cnt+=1;
        }
    }
    else{
        cout<<"0";
    }
    if(cnt==3){
        if(s1[2]<='C'){
            if(s1[2]+1!=s2[2] || s1[2]-1!=s2[2]){
                cout<<"0";
            }
    }
    else if(s1[2]>='C'){
        if(s1[2]+2!=s2[2] || s1[2]-2!=s2[2]){
                cout<<"0";
            }
    }
}
    else{
        cout<<"1";
    }
    return 0;
}
