#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n,m;
int sum,id,cnt,ans;
int a[maxn];
int cha[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        cha[i] = a[i] - a[i - 1];
    }
    for(int i = 1;i <= n;i++){
        int cnt = 0,id = i,sum = 1;
        while((cnt + cha[id] * sum) <= m && id <= n){
            cnt += cha[id] * sum;
            id++;
            sum++;
            //cout << cnt << " ";
        }
        ans = max(ans,sum);
    }
    cout << ans;
    return 0;
}
