#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=1e5+10;
int c1,c2;
string s1,s2;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    int rp=(s1[0]-'0')*10+(s1[1]-'0'),xp=(s2[0]-'0')*10+(s2[1]-'0');
//    cout<<rp<<' '<<xp<<'\n';
    if(rp==xp) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    char rc=s1[2],xc=s2[2];
    if(((rc<='C'&&xc<='C')||(rc>'C'&&xc>'C'))) cout<<1;
    else{
        cout<<"00";
        return 0;
    }
//    cout<<'\n'<<xc<<' '<<rc<<'\n';
    if(rc+1==xc||xc+1==rc) cout<<1;
    else cout<<0;
    return 0;
}
