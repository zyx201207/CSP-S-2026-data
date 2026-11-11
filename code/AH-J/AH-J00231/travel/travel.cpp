#include<bits/stdc++.h>
using namespace std;
int ifline(char x){
    if(x=='A' || x=='B' || x=='C') return 1;
    if(x=='D' || x=='F') return 2;
    return x-'A';
}
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000\n";
        return 0;
    }
    cout<<1;
    if(s1[0]==s2[0] && s1[1]==s2[1]){
        cout<<1;
        if(ifline(s1[2])==ifline(s2[2])){
            cout<<1;
            char a=s1[2],b=s2[2];
            if((a=='A' && b=='B') || (a=='C' && b=='B') || (a=='B' && b=='A') || (a=='B' && b=='C') || (a=='F' && b=='D') || (a=='D' && b=='F')){
                cout<<1<<'\n';
            }else{
                cout<<0<<'\n';
            }
        }else{
            cout<<"00\n";
            return 0;
        }
    }else{
        cout<<"000\n";
        return 0;
    }
    return 0;
}
