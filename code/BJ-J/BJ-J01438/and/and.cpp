#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(m == 1){
        long long maxx = -1;
        for(int i = 1;i <= n;i++){
            maxx = max(maxx,a[i]);
        }
        cout << maxx;
    }else if(m == 2){
        long long maxx = -1;
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                maxx = max(maxx,(a[i]&a[j]));
            }
        }
        cout << maxx;
    }else if(m == n){
        long long maxx = a[1];
        for(int i = 2;i <= n;i++){
            maxx &= a[i];
        }
        cout << maxx;
    }else if(m == n - 1){
        long long maxx = -1;
        for(int i = 1;i <= n;i++){
            long long sum;
            if(i == 1){
                sum = a[2];
            }else{
                sum = a[1];
            }
            for(int j = 1;j <= n;j++){
                if(j == i){
                    continue;
                }
                sum &= a[j];
            }
            maxx = max(maxx,sum);
        }
        cout << maxx;
    }
    return 0;
}
