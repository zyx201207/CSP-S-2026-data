#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, a[500005], c[300005];

void findly(int k){
    int b[300005] = {0};
    int d[500005];
    for(int i=1;i<=n;i++){
        d[i] = a[i];
    }
    for(int i=k;i<=n;i++){
        if(b[d[i]]!=0){
            for(int j=b[d[i]];j<i;j++){
                b[d[j]] = 0;
                d[j] = 0;
            }
        }
        b[d[i]] = i;
    }
    for(int i=1;i<=m;i++){
        if(b[i]!=0) c[i]++;
    }
}

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        findly(i);
    }
    for(int i=1;i<=m;i++){
        cout << c[i] << ' ';
    }
    return 0;
}
