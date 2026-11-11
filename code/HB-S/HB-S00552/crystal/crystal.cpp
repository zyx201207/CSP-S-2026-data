#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long cha[500005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n;
    long long m;
    cin >> n >> m;
    for(long long i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(long long i = 2;i <= n;i++){
        cha[i] = a[i] - a[i - 1];
    }
    long long cnt = 0,ans = 0;
    for(long long i = 2,j = 1;i <= n;i++){
        cnt += cha[i]*(i - j);
        while(cnt > m){
            j++;
            cnt -= (a[i] - a[j]);
        }
        ans = max(ans,i - j + 1);
    }
    cout << ans << '\n';
    return 0;
}
