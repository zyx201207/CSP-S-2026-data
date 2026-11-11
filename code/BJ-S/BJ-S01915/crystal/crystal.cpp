#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    int a[1000000];
    for(long long i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a, a + n);
    long long sumax = 0;
    for(long long i = 0;i <= m;i++){
        for(long long j = 0;j < n;j++){
            long long sum = 1;
            for(long long k = j + 1;k < n;k++){
                if(a[j] == a[k])
                sum++;
            }
            if(sum > sumax){
                sumax = sum;
            }
        }
        a[0] += 1;
        sort(a, a + n);
    }
    cout << sumax;
}
