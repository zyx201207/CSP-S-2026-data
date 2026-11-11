#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s1,s2,c1,c2;char t1,t2;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1.substr(0,2)==s2.substr(0,2)){
            cout<<1;t1=s1[2],t2=s2[2];
            if((t1=='D'||t1=='E')&&(t2=='D'||t2=='E')||(!(t1=='D'||t1=='E'))&&(!(t2=='D'||t2=='E'))){
                cout<<1;
                if(abs(int(t1)-int(t2))==1) cout<<1;
                else cout<<0;
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
