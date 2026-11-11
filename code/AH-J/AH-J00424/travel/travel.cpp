#include<bits/stdc++.h>
using namespace std;
string s1,d1,s2,d2;
int s[120];
void init(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return ;
}
int main(){
    init();
    cin>>s1>>d1>>s2>>d2;
    if(s1==s2){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    bool flag=false;
    for(int i=0;i<2;i++){
        if(d1[i]!=d2[i]){
            cout<<"000";
            return 0;
        }
    }
    s['F']=2;
    s['D']=2;
    s['C']=1;
    s['B']=1;
    s['A']=1;
    cout<<1;
    if(s[d1[2]]!=s[d2[2]]){
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(abs(d1[2]-d2[2])==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
