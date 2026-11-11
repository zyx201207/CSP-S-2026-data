#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin >> c >> t;
    int n,b;
    int x[10005];
    for(int i = 1;i <= t;i++){
        cin >> n >> b;
        for(int j = 1;j <= n;j++){cin >> x[j];}
    }

    int sum = 0;
    int a[10005][10005];
    while(1){
        int num;
        for(int i = 1;i <= n;i++){
            for(int j = i;j <= n;j++){
                num = x[j]-x[i];
                if(x[j]-x[i]<=d && num < x[j]-x[i]){
                    num = x[j]-x[i];
                    a[i][1] = i;
                    a[i][j] = j;
                    for(int h = 2;h <= n-j;h++){
                        x[h-1] = x[h];
                    }
                }
                for(int k = 1;k <= n;k++){
                    for(int w = i;w <= n;w++){
                        if(a[k][w] != a[i][j]){
                            sum++;
                        }
                    }
                }
            }
        }
        n -= j;
        if(n == 0){break;}
    }
    cout << sum;


    return 0;
}
