#include <bits/stdc++.h>
using namespace std;

int n, m, ts = 0, cnt[500005], a[500005], last[500005], stk[500005];
bool flag = true;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        flag |= (a[i] <= a[i + 1]);
    }
    if (flag && n > 500){
         for (int i = 1; i <= n; i++){
            for (int j = a[i]; j <= m; j++){
                cnt[i] ++;
            }
         }
         for (int i = 1; i <= m; i++){
            printf("%d ", cnt[i]);
        }
        return 0;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            last[j] = -1;
        }
        for (int j = 1; j <= ts; j++){
            stk[j] = 0;
        }
        ts = 0;
        for (int j = i; j <= n; j++){
            if (last[a[j]] != -1){
                int pos = last[a[j]];
                while (ts >= pos && ts > 0){
                    last[stk[ts]] = -1;
                    ts--;
                }
            }
            stk[++ts] = a[j];
            last[a[j]] = ts;
            //for (int i = 1; i <= ts; i++){
//
            //    printf("%d ", stk[i]);
            //}
            //printf("\n");
        }
        for (int i = 1; i <= ts; i++){
            cnt[stk[i]] ++;
            //printf("[%d] ", stk[i]);
        }
        //printf("\n");
    }
    for (int i = 1; i <= m; i++){
        printf("%d ", cnt[i]);
    }
    return 0;
}

