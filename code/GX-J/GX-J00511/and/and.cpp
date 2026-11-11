#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    long long a[n];
    for (long long i = 1;i <= n;i++){
        cin >> a[i];
    }
    long long Max = 0;
    for (long long i = 1;i <= n;i++){
        for(long long j = i;j <= n;j++){
            Max = max(Max,a[i] ^ a[j]);
        }
    }
    cout << Max;
    return 0;
}
