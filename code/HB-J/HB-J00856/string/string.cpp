#include<bits/stdc++.h>
using namespace std;
int a[100010];
char c[100010];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    int ans = 0, cnt = 0;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
        if(ans < a[i])
            ans = a[i];
    }
    for(int i = 1;i <= n;i++){
        if(a[i] == ans)
            continue;
        cnt += a[i];
    }
    cout << cnt;
    return 0;
}
