#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    pair<int,string>  x <fist<int>,second<string>>,y <fist<int>,second<string>>;
    cin>>a;
    cin>>x.fist>>x.second;
    cin>>b;
    cin>>y.fist>>y.second;
    if(a == b){
        cout>>"1";
        if(x.first == y.fist){
            cout>>"1";
            if((x.second<=C&&y.second<=C)||(x.second>C&&y.second>C)){
                cout>>"1";
                if((x.second+1==y.second)||(x.second-1==y.second)){
                    cout>>"1";
                }else{
                    cout>>"0";
                    return 0;
                }
            }else{
                    cout>>"00";
                    return 0;
                }
        }else{
                    cout>>"000";
                    return 0;
                }
    }else{
                    cout>>"0000";
                    return 0;
                }
}