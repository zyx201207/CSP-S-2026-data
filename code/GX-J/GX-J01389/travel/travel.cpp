#include<bits/stdc++.h>
using namespace std;
int r,x;
string c,s,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>c2>>s2;
    if(c!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(s[0]!=s2[0]||s[1]!=s2[1]){
        cout<<"000";
        return 0;
    }
    cout<<1;
    r=s[2]-'A'+1;
    x=s2[2]-'A'+1;
    if((r<=3&&x<=3)||(r>3&&x>3)){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if(r==x+1||r==x-1) cout<<1;
    else cout<<0;
    return 0;
}
