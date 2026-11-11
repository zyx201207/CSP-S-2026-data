#include<bits/stdc++.h>
using namespace std;
long long a[500009];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    long long ans = 1;
    long long pos = 1;
    long long cnt = 0;
    long long anss = 1;
    for(int i = 2;i <= n;i++){
        if(m >= cnt + (a[i] - a[i - 1]) * (i - pos)){
            ans++;
            cnt += (a[i] - a[i - 1]) * (i - pos);
        } else {
            ans++;
            cnt += (a[i] - a[i - 1]) * (i - pos);
            while(cnt > m){
                cnt -= a[i] - a[pos];
                pos++;
                ans--;
            }
        }
        anss = max(ans,anss);
        //cout << i << ' ' << ans << ' ' << cnt << endl;
    }
    cout << anss << endl;
    return 0;
}
// g++ crystal.cpp -o a -O2 -std=c++14 -Wall
