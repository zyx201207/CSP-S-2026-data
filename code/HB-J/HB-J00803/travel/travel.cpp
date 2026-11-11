#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,m1,s2,m2;
    cin>>s1>>m1>>s2>>m2;
    if(s1!=s2){
        cout<<"0000";
        return 0;
    }
    else{
        cout<<"1";
        if(m1[0]==m2[0]&&m1[1]==m2[1]){
            cout<<"1";
            if((m1[2]<='C'&&m2[2]<='C')||(m1[2]>='D'&&m2[2]>='D')){
                cout<<"1";
                if(abs(m1[2]-m2[2])==1&&m1[2]<='C'){
                    cout<<"1";
                }else if(m1[2]>='D'){
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
    }
    return 0;
}
