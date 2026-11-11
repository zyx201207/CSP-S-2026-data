#include <bits/stdc++.h>
using namespace std;

int c,t,n,d,cnt,ans=0;
int a[2000020];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for (int i=1;i<=t;i++){
        cin >> n >> d;
        cnt=1;
        ans=0;
        cin >> a[cnt];
        for (int j=2;j<=n;j++){
            int u;
            cin >> u;
            if (u-a[cnt]<=d){
                cnt++;
                a[cnt]=u;
            }
        }
        int yu=d+d-1;
        for (int i=1;i<=cnt;i++){
            if (i+yu<=cnt){
                ans++;
            }
        }
        if (d==1){
            cout << 0 << endl;
        }
        else{
           cout << ans << endl;
        }

    }
    return 0;
}
