#include<bits/stdc++.h>
using namespace std;

long long n, m;
long long a[1000000+10];
long long diff[1000000+10];
long long maxx;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i<=n;i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    if(n <= 6000) {
        for(int i = n;i>=1;i--) {
            long long las=i;
            if(maxx > las) break;
            long long v = m;
            long long now = a[i], sum =0;
            long long cnt = 0;
            for(int j = 1;j<=i;j++) {
                diff[++cnt] = now - a[j];
            }
            sort(diff+1, diff+cnt+1);
            for(int j = 1;j<=cnt;j++) {
                if(v>=diff[j]) {
                    v-=diff[j];
                    sum++;
                }
            }
            maxx=max(sum, maxx);
        }
        cout << maxx;
        return 0;
    }
    for(int i = n;i>=1;i--) {
        long long v= m, cnt=0;
        long long now = a[n], sum=0;
        for(int j = 1;j<=n;j++) {
            diff[++cnt] = now - a[j];
        }
        sort(diff+1, diff+cnt+1);
        for(int j = 1;j<=cnt;j++) {
            if(v>=diff[j]) {
                v-=diff[j];
                sum++;
            }
        }
        cout << sum;
    }
    return 0;
}
