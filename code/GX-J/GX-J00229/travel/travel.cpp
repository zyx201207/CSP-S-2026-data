#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie (0);
    cout.tie(0);

    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int z1,z2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else {
        cout<<"0000";
        return 0;
    }

    z1=(s1[0]-'0')*10+(s1[1]-'0');
    z2=(s2[0]-'0')*10+(s2[1]-'0');
    if(z1==z2){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }

    if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F'))){
        cout<<1;
    }else {
        cout<<"00";
        return 0;
    }

    if(abs(s1[2]-s2[2])<=1)cout<<1;
    else cout<<0;
    return 0;
}
