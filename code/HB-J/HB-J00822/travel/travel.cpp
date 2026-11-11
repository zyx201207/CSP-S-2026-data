#include<bits/stdc++.h>

using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(c1==c2&&(s1-s2<=4||s2-s1<=4)){
        cout<<"1";
    }else{
        cout<<"0";
    }
    if(c1==c2&&(s1-s2<=4||s2-s1<=4)&&s1-s2<=2){
       if(s1!=01C&&s2!=01A){
             cout<<"1";
        }else{
            cout<<"0";
        }
   }
   if(c1==c2&&(s1-s2<=4||s2-s1<=4)&&s1-s2<=2){
        if(s1!=01C&&s2!=01A){
            if(s1-s2==1||s2-s1==1){
                cout<<"1";
            }else{
                cout<<"0";
            }
        }else{
            cout<<"0";
        }
   }else{
        cout<<"0";
   }

    return 0;
}
