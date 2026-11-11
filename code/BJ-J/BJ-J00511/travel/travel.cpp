#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int se1,se2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s1>>c1>>s2>>c2;
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            cout<<0<<0<<0<<0;
            return 0;
        }
    }
    se1=c1[2]-'A';
    se2=c2[2]-'A';
    if(c1[1]!=c2[1]||c1[0]!=c2[0])cout<<1000;
    else if((se1>2&&se2<3)||(se1<3&&se2>2))cout<<1100;
    else if(se1-se2!=1&&se1-se2!=-1)cout<<1110;
    else cout<<1111;
    return 0;
}
