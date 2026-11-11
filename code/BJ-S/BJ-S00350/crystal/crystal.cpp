#include <bits/stdc++.h>
using namespace std;
long long n, x, m, maxn=-1;
vector<long long> a;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(long long i = 1; i <= n; ++i){
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for(long long i = n-1; i >= 0; --i){
        long long k = m, sum = 0;
        for(long long j = i-1; j >= 0; j--){
            if(k >= a[i]-a[j]){
                k-=(a[i]-a[j]);
                sum++;
            }
            else break;
        }
        maxn=max(maxn, sum+1);
    }
    cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
