#include<bits/stdc++.h>
using namespace std;
long long c,n,t,d,ls[2000001],ans;
void vio(){
    for(int p = 1;p <= n;p++){
        for(int q = p;q <= n;q++){//区间左右
            if(ls[q] - ls[p] <= d or ls[q] - ls[p] >= 2*d) continue;
            else{
                int cnt = 0;
                for(int v = p+1;v <= q-1;v++){
                    if(ls[v]-ls[p] <= d && ls[q] - ls[v] <= d){
                        cnt++;
                    }
                }
                if(cnt == 2) ans++;
            }
        }
    }
}
void eqr(){
    ans = 0;
    long long ch = ls[2] - ls[1];
    //cout << ch << "* ";
    long long d1 = d / ch * ch;
    if(d < 2 * ch or d >= n*ch) return;
    else{
        ans = n-2*(d/ch)+1;
        return;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c >> t;
    bool r = 1;
    for(int T = 1;T <= t;T++){
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            cin >> ls[i];
            if(i >= 3){
                if(ls[i]-ls[i-1] != ls[i-1]-ls[i-2]){
                    r = 0;
                    //cout << "ft";
                }
            }
        }
        //if(T == 6 or T == 7){
         //   cout << "/ " << ls[1] << " " << ls[2] << " / " << n << " nd " << d << " E " << T << "\n";
        //}
        if(n <= 3){
            cout << 0;
            continue;
        }
        else if(n <= 300){
            vio();
            cout << ans << "\n";
            ans = 0;
        }
        else{
            if(r){
                eqr();
                cout << ans << "\n";
            }
        }
    }
}
