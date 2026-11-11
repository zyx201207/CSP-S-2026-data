#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >>t;
    while(t--){
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            cin >>x[i];
        }
        ll xl,cnt=-1;
        for(int i=1;i<=n;i++){
            xl=x[i];
            if((xl-x[i])%d==0){
                cnt++;
            }
        }
        cout << cnt/2 << " ";
    }
    return 0;
}
