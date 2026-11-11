#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(int i = a;i <= b;i++)
using namespace std;
int n;
ll m;
ll a[500005],cf[500005],qz[500005];
int main(){
    //en...
    //<<xterfusion>> X X XXX
    //KSKBL ZDJD WKZKBL
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    rep(i,1,n){
        cin >> a[i];
    }
    if(n <= 5000){
        sort(a+1,a+1+n);
        int ans = 1;
        rep(i,1,n){
            ll k = 0;
            int fl = 1;
            for(int j = i-1;j >= 1;j--){
                k += a[i]-a[j-1];
                fl = i-j+1;
                if(k > m){
                    break;
                }
            }
            //cout << k << endl;
            ans = max(ans,fl);
        }
        cout << ans;
    }else{
        int gc = a[2]-a[1];
        int i = 1;
        while(m >= 0){
            m -= i*gc;
            i++;
        }
        cout << i-1;
    }

    return 0;
}
