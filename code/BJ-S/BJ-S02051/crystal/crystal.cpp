#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[500010], maxn = 0, cha;
bool f;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != i){
            f = 1;
        }
    }
    if(!f){
        int cnt = 0;
        for(int i = n-1; i >= 1; i--){
            if(m >= a[n]-a[i]){
                cnt++;
                m -= (a[n]-a[i]);
            }else{
                break;
            }
        }
        cout << cnt;
        return 0;
    }
    f = 0;
    cha = a[2]-a[1];
    for(int i = 3; i <= n; i++){
        if(a[i]-a[i-1] != cha){
            f = 1;
        }
    }
    if(!f){
        int cnt = 0;
        for(int i = n-1; i >= 1; i--){
            if(m >= a[n]-a[i]){
                cnt++;
                m -= (a[n]-a[i]);
            }else{
                break;
            }
        }
        cout << cnt;
        return 0;
    }
    sort(a+1, a+n+1);
    for(int i = 2; i <= n; i++){
        int b = m;
        int cnt = 1;
        for(int j = i-1; j >= 1; j--){
            if(a[i]-a[j] <= b){
                cnt++;
                b -= (a[i]-a[j]);
            }else{
                break;
            }
        }
        maxn = max(maxn, cnt);
    }
    cout << maxn;
    return 0;
}
