#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a, b, c, d;
    cin>>a>>b>>c>>d;
    if(b[2] == 'F') b[2]--;
    if(d[2] == 'F') d[2]--;
    int cnt = 0;
    if(a == c){
        cnt++;
        if(b[0] == d[0] && b[1] == d[1]){
            cnt++;
            if((b[2] <= 'C') == (d[2] <= 'C')){
                cnt++;
                if(abs(b[2] - d[2]) == 1) cnt++;
            }
        }
    }
    for(int i = 1;i <= 4;i++) printf("%d", (i <= cnt));
    return 0;
}
