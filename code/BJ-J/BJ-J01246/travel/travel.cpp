#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(s1[0]!=s2[0] || s1[1]!=s2[1]){
        cout<<"000";
        return 0;
    }
    int x=s1[2]-'A'+1;
    int y=s2[2]-'A'+1;
    cout<<1;
    if(x<=3 && y<=3){
        cout<<1;
        if(abs(x-y)==1)cout<<1;
        else cout<<0;
    }else if(x>=4 && y>=4)cout<<"11";
    else cout<<"00";
    return 0;
}