#include <iostream>
using namespace std;
long long a[500005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    cin >> a[1];
        for(int j = 2; j <= n; j++){
            cin >> a[j];
        }
    for(int i = 1; i <= n; i++){
        for(int j = 2 + i; j <= n; j++){
            for(int k = 1; k < j; k++){
                if(a[j] == a[k]){
                    for(int l = 1; l <= k; l++){
                        a[l] = 0;
                    }
                }
            }
        }
        for(int j = 1; j <= n; j++){
            ans[a[j]]++;
        }
    }
    for(int j = 1; j <= m; j++){
        cout << ans[j] << " ";
    }
    return 0;
}
