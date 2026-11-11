#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string ac,bc,az,bz;
    cin>>ac>>az>>bc>>bz;
    int ap = (az[0]-'0')*10+az[1]-'0';
    int bp =(bz[0]-'0')*10+bz[1]-'0';
    char al = az[2]-'A'+1,bl=bz[2]-'A'+1;
    if(ac==bc) cout<<1;
    else cout<<0;
    if(ac==bc && ap == bp) cout<<1;
    else cout<<0;
    if(ac == bc && ap == bp){
        if((al<=3 && bl<=3) || (al>=4 && bl>=4)) cout<<1;
        else cout<<0;
    }
    else cout<<0;
    if(ac == bc && ap == bp){
        if((al<=3 && bl<=3) || (al>=4 && bl>=4)){
            if(al-bl==1 or al-bl==-1)cout<<1;
            else cout<<0;
        }
        else cout<<0;
    }
    else cout<<0;
    return 0;

}
