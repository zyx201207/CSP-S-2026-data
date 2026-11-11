#include<bits/stdc++.h>
using namespace std;
const long long N = 5 * 1e5 + 10;
int n;
long long m, sum = 0, cnt = 0;
long long a[N];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >>> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        while(sum <= m){
            a[i] += 1;
            sum += 1;
            for(int j = i + 1; j <= n; j++){
                if(a[i] == a[j]){
                    cnt++;
                    a[i] += 1;
                    a[j] += 1;
                    sum += j;
                }else{
                    break;
                }
            }
        }
    }
    cout << cnt;
    return o;
}