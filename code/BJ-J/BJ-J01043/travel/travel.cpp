#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a = 0,b = 0;
    string x = "",y = "",ans = "0000";
    cin >> a >> x >> b >> y;
    if(a == b){
        ans[0] = '1';
        if(x[0] == y[0] && x[1] == y[1]){
            ans[1] = '1';
            if((x[2] == 'A' && y[2] == 'B') || (x[2] == 'B' && y[2] == 'A') || (x[2] == 'B' && y[2] == 'C') || (x[2] == 'C' && y[2] == 'B') || (x[2] == 'A' && y[2] == 'C') || (x[2] == 'C' && y[2] == 'A') || (x[2] == 'D' && y[2] == 'E') || (x[2] == 'E' && y[2] == 'D')){
                ans[2] = '1';
                if((x[2] == 'A' && y[2] == 'B') || (x[2] == 'B' && y[2] == 'A') || (x[2] == 'B' && y[2] == 'C') || (x[2] == 'C' && y[2] == 'B') || (x[2] == 'D' && y[2] == 'E') || (x[2] == 'E' && y[2] == 'D'))
                    ans[3] = '1';
            }
        }
    }
    cout << ans;
    return 0;
}