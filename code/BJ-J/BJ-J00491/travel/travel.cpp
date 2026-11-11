#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
inline int line(const string & s){
    return (s[0]-'0')*10+(s[1]-'0');
}
inline int getS(const string &s){
    return (s[2]-'A'+1);
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b>>c>>d;
    bool f1 = (a==c);
    bool f2 = (f1&&line(b)==line(d));
    bool f3 = (f2&&((getS(b)<=3&&getS(d)<=3)||(getS(b)>=4&&getS(d)>=4)));
    bool f4 = (f3&&(abs(getS(b)-getS(d))==1));
    cout<<f1<<f2<<f3<<f4<<flush;
    return 0;
}
