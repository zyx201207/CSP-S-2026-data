#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f1,f2,f3,f4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    f1=(c1==c2);
    if(!f1){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    f2=(s1.substr(0,2)==s2.substr(0,2));
    if(!f2){
        cout<<"000";
        return 0;
    }
    cout<<1;
    f3=((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A'));
    if(!f3){
        cout<<"00";
        return 0;
    }
    cout<<1;
    f4=((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B'));
    if(!f4) cout<<0;
    else cout<<1;
    return 0;
}
