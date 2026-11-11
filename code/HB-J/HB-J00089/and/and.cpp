#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    if(m == 1){
        long long maxn = a[1];
        for(int i=2; i<=n; i++) maxn = max(maxn,a[i]);
        cout << maxn;
    }
    else if(m == 2){
        long long maxn = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i != j){
                    maxn = max(maxn, a[i] & a[j]);
                }
            }
        }
        cout << maxn;
    }
    else if(m == 3){
        long long maxn = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                for(int k=1; k<=n; k++){
                    if(i != j && j != k && i != k){
                        int xx = a[i] & a[j];
                        maxn = max(maxn, xx & a[k]);
                    }
                }
            }
        }
        cout << maxn;
    }
    return 0;
}
