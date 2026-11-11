#include <bits/stdc++.h>
using namespace std;
//g++ migrate.cpp -o migrate -std=c++14 -Wall -O2

typedef long long ll;
const int N = 2e6 + 5;
int subtask, T;
int n;
ll dis;
ll pos[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    // freopen("migrate4.in", "r", stdin);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin>>subtask>>T;
    while(T--){
        cin>>n>>dis;
        if(subtask==11 || subtask==12){
            for(int i=1; i<=n; i++){
                cin>>pos[i];
            }
            if(n == 1){
                cout<<0<<'\n';
                continue;
            }
            ll d = pos[2] - pos[1];
            if(d > dis){
                cout<<0<<'\n';
                continue;
            }
            ll il = dis / d;
            ll lst = (ll)n + 1 - 2 * il;
            ll ans = max(lst, (ll)0);
            cout<<ans<<'\n';
        }
        // /*
        else if(subtask==13 || subtask==14){
            int hom = 0;
            for(int i=1; i<=n; i++){
                cin>>pos[i];
                if(pos[i] - pos[1] <= dis) hom = i;
            }
            cout<<0<<'\n';
        }
        // */
    }
    return 0;
}

/*
0 3
4 2
1 2 3 4
5 2
1 2 3 4 5
5 3
-2 -1 0 1 2 
*/
