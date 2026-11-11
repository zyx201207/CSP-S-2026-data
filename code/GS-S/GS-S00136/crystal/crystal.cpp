#include<bits/stdc++.h>
using namespace std;

#define N 1000005
int a[N];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n,m;
    int ans = 0;
    int A = 0;
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        A = A + a[i];
    }

    for(int i = 1; i <= m; ++i){

        if((A / n) >= a[i]){
            a[i]+1;
            ans++;
        }
    }

    printf("%d", ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
