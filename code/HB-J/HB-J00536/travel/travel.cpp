#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c1,c2,s1,s2;
bool check(char a,char b)
{
    if(a=='A'&&b=='B') return 1;
    if(a=='B'&&b=='A') return 1;
    if(a=='C'&&b=='B') return 1;
    if(a=='B'&&b=='C') return 1;
    if(a=='D'&&b=='F') return 1;
    if(a=='F'&&b=='D') return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        string ss1=s1;ss1.erase(2,1);
        string ss2=s2;ss2.erase(2,1);
        if(ss1==ss2){
            cout<<"1";
            char cc1=s1[2],cc2=s2[2];
            if((cc1>='A'&&cc1<='C'&&cc2>='A'&&cc2<='C')||(cc1=='D'&&cc2=='F')||(cc1=='F'&&cc2=='D')){
                cout<<"1";
                if(check(cc1,cc2)){
                    cout<<"1";
                }else cout<<"0";
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
