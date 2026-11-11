#include <bits/stdc++.h>
using namespace std;

int s[10000000000000000];

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int n, m;
    cin >> n >>m;
    int a[n+10];
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }

    int k, cnt=0;
    for (int i=1;i<n;i++){
        k=a[i];
        for (int j=i+1;j<=n;j++){
            s[cnt]=k&a[j];
            cnt++;
        }
    }

    int ans=0;
    for (int i=0;i<=cnt;i++){
        if (ans <= s[i]){
            ans=s[i];
        }
    }
    cout << ans;

    return 0;
}
