/*
CSP-J2 2026 RP++
A 13min 100pts.
*/
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(false);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            if(((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))||((s1[2]=='A'||s1[2]=='C'||s1[2]=='B')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))){
                cout<<"1";
                if(((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||s1[2]=='C'&&s2[2]=='B'){
                    cout<<"1";
                }else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    
    return 0;
}
/*
CSP-J2 2026 LOG:
0843 AC question A.
0900 AC question B.
0909 have a rest.
0912 i'm back!
1025 got 55pts on question C.
1055 got 48pts on question D.
1117 finish all work,303pts leave.
1119 finish all check.
...waiting for CSP-S2 2026 this afternoon...
*/