#include<bits/stdc++.h>
using namespace std;
int c[2],r[2],h[2];

signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    char x;
    for(int i=0;i<=1;i++){
        cin>>x;c[i]+=(x-'0')*10;
        cin>>x;c[i]+=(x-'0');

        cin>>x;r[i]+=(x-'0')*10;
        cin>>x;r[i]+=(x-'0');

        cin>>x;h[i]=(x-'A');
    }

    if(c[0]==c[1]){
        if(r[0]==r[1]){
            if((h[0]<=2&&h[1]<=2)||(h[0]>2&&h[1]>2)){
                if(abs(h[0]-h[1])==1) cout<<"1111";
                else cout<<"1110";
            }
            else cout<<"1100";
        }
        else cout<<"1000";
    }
    else cout<<"0000";
    return 0;
}