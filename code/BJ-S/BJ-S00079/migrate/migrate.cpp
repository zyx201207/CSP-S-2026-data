#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,c[2000005],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> x[i];
        }
        if(x[2] - x[1] > d){
            cout << 0 << "\n";
        }
        else if(x[2] - x[1] == d){
            cout << 0 << "\n";
        }
        else{
            cout << n - (x[2] - x[1]) * d + 1 << "\n";
        }
    }
    return 0;
}
