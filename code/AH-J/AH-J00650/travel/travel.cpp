#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ll a,b,ap,bp;
    string aseat,bseat;
    cin>>a>>aseat>>b>>bseat;
    ap=(aseat[0]-'0')*10+(aseat[1]-'0');
    bp=(bseat[0]-'0')*10+(bseat[1]-'0');
    ll aw=aseat[2]-'A'+1;
    ll bw=bseat[2]-'A'+1;
    if(a==b){
        cout<<1;
        if(ap==bp){
            cout<<1;
            if(aw>=1&&bw<=3||aw>=4&&bw<=6){
                cout<<1;
                if(aw==bw+1||bw==aw+1||bw==4&&aw==6||aw==4&&bw==6){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<0<<0;
            }

        }else{
            cout<<0<<0<<0;
        }
    }else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}
