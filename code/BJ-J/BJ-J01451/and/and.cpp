#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = 200005;
long long a[MAXN];

bool cmp(long long a, long long b) {
    return a > b;
}

int main() {

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];                    
    }

    sort(a, a + n, cmp);                  
    long long ans = a[0];

    for (int i = 1; i < m; i++) {
        ans &= a[i];                      
    }
    cout << ans;
    return 0;
}