#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d;
ll x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> x[i];
        }
        if(c == 11 || c == 12){
            ll cha = x[2]-x[1];
            ll tmp = d / cha;
            if(n - tmp * 2 + 1 >= 0)cout << n-tmp*2+1 << endl;
            else cout << 0 << endl;
        }
        ll cnt = 0,pos1 = n,pos2 = n+1;
        for(int i = 1;i <= n;i++){
            if(max(x[i]-x[1],x[n]-x[i]) <= d){
                cnt++;
                if(cnt == 2)pos1 = i;
                if(cnt == 3)pos2 = i;
            }
        }
        cout << pos2 - pos1 - 1 << endl;
    }
    return 0;
}
