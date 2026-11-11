#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool same(char a,char b){
    if(a>b)swap(a,b);
    return ((a=='A'&&b=='B')||(a=='A'&&b=='C')||(a=='B'&&b=='C')||(a=='D'&&b=='F'));
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if(same(s1[2],s2[2])){
                cout<<1;
                if(abs(s1[2]-s2[2])==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }

    return 0;
}
