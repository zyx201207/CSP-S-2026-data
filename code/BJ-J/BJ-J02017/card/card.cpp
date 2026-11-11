#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[300010] , cnt[300010];
bool flag[300010];
signed main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n , m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];

    }
    for(int i = 1;i <= m;i++){
        flag[i] = false;
    }
    int xx = 0;
    for(int i = 1;i <= n;i++){
        cout << 2;
        if(flag[a[i]] == 0){
            cnt[a[i]] += i;
            flag[a[i]] = 1;
            xx++;
        }
        else {
            cnt[a[i]] += i - 1;
            int x = i - 1;
            while(a[x] != a[i]){
                x--;
            }
            int y = i - 1; 
            while(y != x){
                cnt[a[y]] -= x;
            }   
        }
    }
    for(int i = 1;i <= xx;i++){
        cout << cnt[i] << " ";
    }
    return 0;
}