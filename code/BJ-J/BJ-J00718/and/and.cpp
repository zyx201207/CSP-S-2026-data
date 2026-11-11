#include<bits/stdc++.h>
using namespace std;
int n,m;
struct kkk{
    int num,le1;
}a[200010];
int p[35];
int idx;
int ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i].num;
        int x = a[i].num,y = 1;
        while(x){
            if(x & 1){
                p[y]++;
            }
            x >>= 1;
            y++;
        }
        a[i].le1 = y-1;
    }
    for(idx = 33;idx >= 0; idx--){
        if(p[idx] >= m){
            break;
        }
    }

    while(idx > 0){
        //cout <<idx << '\n';
        const int mm = (1 << (idx-1));
        ans += mm;
        int sy = 0;

        for(int i = 0;i <= 33; i++){
            p[i] = 0;
        }
        for(int i = 1;i <= n; i++){
            if(a[i].num & mm){
                a[++sy].num = a[i].num - mm;
                a[sy].le1 = 0;
                int x = a[sy].num,y = 1;
                while(x){
                    if(x & 1){
                        p[y]++;
                    }
                    x >>= 1;
                    y++;
                }
                a[sy].le1 = y-1;
            }
        }
        n = sy;
        //cout <<'&';
        for(idx = 33;idx >= 0; idx--){
            if(p[idx]){
                //cout << idx << ' ' << p[idx] << '\n';
            }
            if(p[idx] >= m){
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
