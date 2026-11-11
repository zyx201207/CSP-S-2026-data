#include<bits/stdc++.h>
using namespace std;
long long a[500002],cha[500002];
long long n,m,ans = 0;
int op = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hub.in","r",stdin);
    freopen("hub.out","r",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] != a[i - 1] && i >= 2){
            op = 1;
        }
    }
    if(m == 0){
        op = 3;
    }
    sort(a+1,a+1+n);
    for(int i = 3;i <= n;i++){
        if(a[i] - a[i-1] != a[2] - a[1]){
            break;
        }
        if(i == n){
            op = 2;
        }
    }
    if(op == 0){
        cout << n;
        return 0;
    }
    else if(op == 2){
        int w = a[1] - a[2];
        ans = abs(m / w);
        cout << ans;
        return 0;
    }
    else if(op == 3){
        for(int i = 1;i<=n;i++){
            cha[a[i]]++;
        }
        for(int i = 1;i<=100000;i++){
            ans = max(ans,cha[i]);
        }
        cout << ans;
        return 0;
    }
    cout << "";
    long long sum,b;
    for(int i = 2;i <= n;i++){
        sum = 1;
        b = m;
        for(int j = i - 1;j >= 1;j--){
            if(a[j] != a[i] && a[i] - a[j] >= b){
                b -= abs(a[i] - a[j]);
                sum++;
                cout << sum <<endl;
            }
            if(b == 0){
                break;
            }
        }
        ans = max(sum,ans);
    }
    cout << ans;
}
