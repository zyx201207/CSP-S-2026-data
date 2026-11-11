#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        int aa,bb;
        for(int i=0;i<2;i++){
            if(a2[i]!=b2[i]){
                cout<<"1000";
                return 0;
            }
        }
        if(a2[2]-'A'<3){
            aa=0;
        }
        else{
            aa=1;
        }
        if(b2[2]-'A'<3){
            bb=0;
        }
        else{
            bb=1;
        }
        if(aa==bb){
            if(aa==1||a2[2]-'A'==0&&b2[2]-'A'==1||a2[2]-'A'==1&&b2[2]-'A'==2||a2[2]-'A'==1&&b2[2]-'A'==0||a2[2]-'A'==2&&b2[2]-'A'==1){
                cout<<"1111";
                return 0;
            }
            cout<<"1110";
            return 0;
        }
        cout<<"1100";
        return 0;
    }
    else{
        cout<<"0000";
    }
    return 0;
}
