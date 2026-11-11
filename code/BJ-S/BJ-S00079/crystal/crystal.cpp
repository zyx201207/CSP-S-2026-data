#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans = 1,cnt,mid;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] == a[i - 1]){
            ans++;
        }
    }
    sort(a + 1,a + n + 1);
    mid = (n % 2 == 0 ? (a[(long long)n / 2] + a[(long long)n / 2 + 1]) / 2 : a[(long long)n / 2 + 1]);
    for(int i = 1;i <= n;i++){
        b[i] = abs(a[i] - mid);
    }
    while(m > 0 && cnt < n / 2){
        if(m >= b[++cnt]){
            m -= b[cnt];
            ans++;
        }
        else{
            cnt++;
        }
    }
    while(m > 0 && cnt < n){
        if(m >= cnt * (a[cnt + 1] - a[cnt])){
            m -= cnt * (a[cnt + 1] - a[cnt]);
            cnt++;
            ans++;
        }
        else{
            cnt++;
        }
    }
    cout << (ans <= 1 ? 0 : ans);
    return 0;
}