#include<iostream>
#include<algorithm>
using namespace std;
const int mxn = 2e5 + 10;
int n, m, a[mxn];
pair<int, int> p[mxn];
bool cmp(pair<int, int> x, pair<int, int> y){
    if(x.first != y.first) return x.first > y.first;
    else return x.second > y.second;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[i].second = a[i];
        int b = (1 << 30), cnt = 0;
        while(a[i]){
            if(a[i] >= b){
                a[i] -= b;
                cnt++;
            }
            b /= 2;
        }
        p[i].first = cnt;
    }
    sort(p+1, p+n+1, cmp);
    int ans = 0;
    for(int i = 1; i <= m; i++){
        if(i == 1) ans = p[i].second;
        else ans &= p[i].second;
    }
    cout << ans << endl;
    return 0;
}
