#include<bits/stdc++.h>
//const int maxn=1e8+5;
//#define int long long
using namespace std;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    string h1,h2;
    cin>>a>>h1>>b>>h2;
    int h1p=(h1[0]-'0')*10+h1[1];
    int h1h=h1[2]-'A'+1;
    int h2p=(h2[0]-'0')*10+h2[1];
    int h2h=h2[2]-'A'+1;
    cout<<(a==b);
    if(a!=b){cout<<"000";return 0;}
    cout<<(h1p==h2p);
    if(!(h1p==h2p)){cout<<"00";return 0;}
    cout<<((h1h<=3&&h2h<=3)||(h1h>3&&h2h>3));
    if(!((h1h<=3&&h2h<=3)||(h1h>3&&h2h>3))){cout<<"0";return 0;}
    cout<<(abs(h1h-h2h)==1);
    return 0;
}
