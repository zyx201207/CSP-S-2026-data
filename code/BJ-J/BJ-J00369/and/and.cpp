#include <cstdio>
int n, m, ans, a[200005];
bool ng[200005];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 29; i >= 0; i--){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(!ng[j]){
                cnt += (a[j] >> i) & 1;
            }
        }
        if(cnt >= m){
            ans |= 1 << i;
            for(int j = 0; j < n; j++){
                if(!((a[j] >> i) & 1)){
                    ng[j] = 1;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
