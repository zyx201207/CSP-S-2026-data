#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    sort(a + 1,a + n + 1);

    int l = 1,r = 2;
    while(a[l] <= a[r] && m > 0){
        if(a[l] == a[r] && a[r] == a[r + 1]){
            l += 1,r += 1;
        }
        if(a[l] < a[r] && a[r] <= a[r + 1]){
            a[l] += 1;
            m -= 1;
        }
        else if(a[l] == a[r] && a[r] <= a[r + 1]){
            a[r] += 1;
            m -= 1;
        }
    }
    for(int i = 1;i <= n;i++){
        if(a[i] == a[r]) cnt ++;
        //cout << a[i] << ' ';
    }
    cout << cnt;
    return 0;
}
