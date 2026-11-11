#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }

    if(b[0]==d[0]&&b[1]==d[1]){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }

    map <char,int> mp1,mp2;
    mp1['A']=1;
    mp1['B']=1;
    mp1['C']=1;
    mp1['D']=2;
    mp1['F']=2;
    if(mp1[b[2]]==mp1[d[2]]){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }

    mp2['A']=1;
    mp2['B']=2;
    mp2['C']=3;
    mp2['D']=5;
    mp2['F']=6;
    if(abs(mp2[b[2]]-mp2[d[2]])==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
