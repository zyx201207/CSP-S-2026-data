#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

ll a[200005];
int s[200005][35];
int p[200005];

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=1;i<=200000;i++){
        p[i] = 1;
    }
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ll r = 1;
        for(int j=1;j<=32;j++){
            r = r * 2;
        }
        for(int j=1;j<=32;j++){
            r = r / 2;
            ll z = a[i] & r;
            if(z != 0){
                s[i][j] = 1;
            }
        }
    }
    ll z = 1;
    for(int i=1;i<=32;i++){
        z = z * 2;
    }
    ll ans = 0;
    for(int i=1;i<=32;i++){
        z = z / 2;
        int cnt = 0;
        for(int j=1;j<=n;j++){
            if(p[j] == 1 && s[j][i] == 1){
                cnt++;
            }
        }
        if(cnt >= m){
            for(int j=1;j<=n;j++){
                if(p[j] == 1 && s[j][i] == 1){
                    p[j] = 1;
                }
                else{
                    p[j] = 0;
                }
            }
            ans = ans + z;
        }
    }
    cout<<ans<<endl;
    return 0;
}
