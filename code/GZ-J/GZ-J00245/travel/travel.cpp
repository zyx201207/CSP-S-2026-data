// GZ-J00245
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string s1,s2,c1,c2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[1] != c2[1] || c1[0] != c2[0]){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(s1[0] != s2[0] || s1[1] != s2[1]){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(s1[2] >= 'D'){
        if(s2[2] >= 'D'){
            cout<<11;
            return 0;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    else if(s2[2] >= 'D'){
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(int(s1[2]) + 1 == int(s2[2]) || int(s2[2]) + 1 == int(s1[2])){
        cout<<1;
    }
    else cout<<0;
    return 0;
}
