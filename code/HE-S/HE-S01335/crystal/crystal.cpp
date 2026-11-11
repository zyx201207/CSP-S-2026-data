#include <bits/stdc++.h>
using namespace std;

long long n,m,cnt = 0,mcnt = 0;
long a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> m;
    for(long long i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);


    for(long long i = 2;i <= n;i++){
        cnt = i;
        for(long long j = 1;j <= i - 1;j++){
            while(a[j] != a[i]){
                a[j]++;
                mcnt++;
            }
        }
        if(mcnt == m) {
            if(a[i] == a[i + 1]) cnt += 1;
            break;
        }
        if(mcnt >= m){
            if(a[i] != a[i + 1]) cnt -= 1;
            break;
        }
    }
    cout << cnt << endl;

    return 0;
}
