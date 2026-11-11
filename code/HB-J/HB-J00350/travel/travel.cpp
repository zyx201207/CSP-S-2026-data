#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool flag=true;
    for(int i=0;i<2;i++){
        if(c1[i]!=c2[i]){
            flag=false;
            cout<<"0000";
            return 0;
        }
    }
    cout<<"1";
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            flag=false;
            cout<<"000";
            return 0;
        }
    }
    cout<<"1";
    if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
        cout<<"1";
        if(abs(int(s1[2])-int(s2[2]))==1){
            cout<<"1";
            return 0;
        }else{
            cout<<"0";
            return 0;
        }
    }else{
        cout<<"00";
    }
    return 0;
}
