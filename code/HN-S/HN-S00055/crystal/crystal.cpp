#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 500000;

int n;
ll m;
int a[MAXN + 10], b[MAXN + 10];
int ans = 0;

bool cmp(const int &a, const int &b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a+n, cmp);

    int l = 0, r = 0, k = m,sum = 0;
    while(r < n){
        if(r == n-1){
            ans = max(ans, sum);
            break;
        }
        if(m >= a[l]- a[r + 1]){
//            cout << m << ' ' << l << ' ' << r <<' ' << sum << "r11" << endl;
            r ++;
            m -= a[l]- a[r];
            sum ++;
//            cout << m << ' ' << l << ' ' << r <<' ' << sum << "r12" << endl;
        }
        else{                     //(m < a[l]- a[r])
//            cout << m << ' ' << l << ' ' << r <<' ' << sum << "r21" << endl;
            ans = max(ans, sum);
//            cout << (a[l] - a[l + 1]) << ' ' << (r - l) << endl;
            m += (a[l] - a[l + 1]) * (r - l);
            l ++;
            if(r<l) r = l;
            sum = r - l + 1;
//            cout << m << ' ' << l << ' ' << r <<' ' << sum << "r22" << endl;
        }

    }
//    for(int i = 0; i < n; i++){
//        cout << a[i]<<' ';
//    }

    ans = max(ans, sum);
    cout << ans << endl;

    return 0;
}
