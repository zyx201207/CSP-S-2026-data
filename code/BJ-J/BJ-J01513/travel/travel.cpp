#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
string c1,s1,c2,s2;
bool f1=1,f2=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<2;i++){
        if(c1[i]!=c2[i]){
            f1=0;
            break;
        }
    }
    if(!f1){
        cout<<"0000";
        return 0;
    }
    else cout<<1;

    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            f2=0;
            break;
        }
    }
    if(!f2){
        cout<<"000";
        return 0;
    }
    else cout<<1;

    if( ((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')) || ((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F'))){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }


    if( (s1[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s2[2]=='C') || (s1[2]=='D'&&s1[2]<='F')){
        cout<<1;
    }else{
        cout<<0;
    }

    return 0;
}
