#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s,c2,c;
    cin>>c1>>s>>c2>>c;
    bool a=1;
    if(c1==c2){
        cout<<a;
        if(s[1]==c[1])cout<<a;
        else {
            cout<<"000";
            return 0;
        }if(s[2]!='F'&&c[2]=='D'||c[2]=='F'&&s[2]!='D'){
            cout<<"00";
            return 0;
        }
        else cout<<a;
        if(s[2]++==c[2]||s[2]--==c[2])cout<<a;
        else cout<<"0";

    }
    else cout<<"0000";
    return 0;
}
