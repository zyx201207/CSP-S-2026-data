#include <bits/stdc++.h>
using namespace std;
struct chapiao{
    int cx;//chexiang
    int pai;
    int lie;
};
chapiao cp[2];
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    if(c1[0]=='0') cp[0].cx=(c1[1]-'0');
    else cp[0].cx=(c1[0]-'0')*10+(c1[1]-'0');
    if(c3[0]=='0') cp[1].cx=(c3[1]-'0');
    else cp[1].cx=(c3[0]-'0')*10+(c3[1]-'0');


    if(c2[0]=='0') cp[0].pai=(c2[1]-'0');
    else cp[0].pai=(c2[0]-'0')*10+(c2[1]-'0');
    if(c4[0]=='0') cp[1].pai=(c4[1]-'0');
    else cp[1].pai=(c4[0]-'0')*10+(c4[1]-'0');

    if(c2[2]=='A') cp[0].lie=1;
    if(c4[2]=='A') cp[1].lie=1;
    if(c2[2]=='B') cp[0].lie=2;
    if(c4[2]=='B') cp[1].lie=2;
    if(c2[2]=='C') cp[0].lie=3;
    if(c4[2]=='C') cp[1].lie=3;
    if(c2[2]=='D') cp[0].lie=14;
    if(c4[2]=='D') cp[1].lie=14;
    if(c2[2]=='F') cp[0].lie=15;
    if(c4[2]=='F') cp[1].lie=15;

    if(cp[0].cx!=cp[1].cx) {
        cout<<"0000"<<endl;
        return 0;
    }
    cout<<1;
    if(cp[0].pai!=cp[1].pai) {
        cout<<"000"<<endl;
        return 0;
    }
    cout<<1;
    if(cp[0].lie-cp[1].lie<=-10||cp[0].lie-cp[1].lie>=10) {
        cout<<"00"<<endl;
        return 0;
    }
    cout<<1;
    if(cp[0].lie-cp[1].lie==-1||cp[0].lie-cp[1].lie==1) {
        cout<<"1"<<endl;
        return 0;
    }
    cout<<0;
    return 0;
}
