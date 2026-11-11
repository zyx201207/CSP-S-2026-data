#include<bits/stdc++.h>
using namespace std;

long long a[200005] = {0};

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long ans = 0,x = 0;
    cin >> n >> m;
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    for (int j = 0;j < n;j++){
        if (a[j] > ans) ans = a[j];
    }
    for (int j = 0;j < n;j++){
        if (a[j] == ans){
            a[j] = 0;
        }
    }
    for (int i = 1;i < m;i++){
        for (int j = 0;j < n;j++){
            if (a[j] > x) x = a[j];
        }
        for (int j = 0;j < n;j++){
            if (a[j] == x) a[j] = 0;
        }
        ans = x;
        x = 0;
    }
    cout << ans;
    return 0;
}