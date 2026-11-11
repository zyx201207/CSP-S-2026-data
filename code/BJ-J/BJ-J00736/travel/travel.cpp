#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
        cout<<"1";
        if(s2.substr(0,2)==s4.substr(0,2)){
            cout<<"1";
            char x1=s2[2],x2=s4[2];
            if(x1<=67&&x2<=67||x2>=68&&x1>=68){
                cout<<"1";
                if(x1==65&&x2==67||x1==67&&x2==65) cout<<"0";
                else cout<<"1";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
