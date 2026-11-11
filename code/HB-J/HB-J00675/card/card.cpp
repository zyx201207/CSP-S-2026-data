#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,m,a[N],val[N],sum[N];
int flag = 0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) if(a[i] <= a[i + 1]) flag += 1;
    if(flag == n - 1){
        m = m + 1;
        for(int i = 1;i <= n;i++){
            if(a[i] != a[i - 1]) m -= 1;
            cout << m << " ";
        }
        return 0;
    }
    for(int i = 1;i <= n;i++){
        int r = 0;
        for(int j = i;j <= n;j++){
            val[++r] = a[j];
            for(int k = r - 1;k >= 1;k--){
                if(val[k] == a[j]){r = k;break;}
            }
        }
        for(int i = 1;i <= r;i++) sum[val[i]] += 1;
    }
    for(int i = 1;i <= m;i++) cout << sum[i] << " ";
    return 0;
}
