#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin >> n >> m;
    int a[10005];
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    int cnt = 0;
    int sum[10005];
    while(1){
        for(int h = 1;h <= n;h++){
            for(int j = h+1;j <= n;j++){
                if(a[h] == a[j]){
                    for(int k = h;k <= j;k++){
                        int num = 0;
                        a[h+num] = a[j+num];
                    }
                }else{
                    for(int i = 1;i <= n;i++){
                        if(a[h] == i){sum[i]++;}
                        if(a[h] != a[h-1]){cnt++;}
                    }
                }
            }
            if(h == n){break;}
        }
    }

    for(int i = 1;i <= cnt;i++){
        cout << sum[i] << " ";
    }

    return 0;
}
