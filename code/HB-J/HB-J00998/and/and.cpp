#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int a[N];

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n , m;
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    if(m == 1){
        sort(a + 1, a + n + 1);
        cout << a[n] << "\n";
    }else if(m == n){
        long long ans = a[1];
        for(int i = 1;i <= n;i ++){
            ans &= a[i];
        }
        cout << ans << "\n";
    }else{
        int temp = n;
        temp &= temp - 1;
        if(temp == 0){//B
            long long ans = n - 1;
            for(int i = 1;i <= m;i ++){
                ans &= (n - i);
            }
            cout << ans << "\n";
        }else if(m == 2){
            long long ans = -1;
            for(int i = 1;i <= n;i ++){
                for(int j = 1;j <= n;j ++){
                    long long temp = a[i];
                    temp &= a[j];
                    ans = max(ans, temp);
                }
            }
            cout << ans << "\n";
        }else{
            long long ans = a[n];
            sort(a + 1, a + n + 1);
            for(int i = 0;i < m;i ++){
                ans &= a[n - i];
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
