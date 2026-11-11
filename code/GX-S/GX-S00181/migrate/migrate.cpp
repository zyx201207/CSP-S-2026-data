#include<bits/stdc++.h>
using namespace std;
int a[2000005];
bool vis[2000005];
int cp[2000005];
bool AAA(int n, int d, int l, int r){
    int c = 0, c1 = 0, c2 = 0;
    for(int i = l; a[i] + d <= a[r]; ){
        int j = i;
        while(a[j + 1] <= a[i] + d && j < n){
            j++;
        }
        i = j;
        while(vis[i]) i--;
        vis[i] = true;
        printf("%d\n", i);
        c++;
    }
    for(int i = l; a[i] + d <= a[r]; ){
        int j = i;
        while(a[j + 1] <= a[i] + d && j < n){
            j++;
        }
        i = j;
        while(vis[i] && i > l) i--;
        if(i <= l) break;
        vis[i] = true;
        printf("%d\n", i);
        c1++;
    }
    if(c1 != c) return false;
    for(int i = l; a[i] + d <= a[r]; ){
        int j = i;
        while(a[j + 1] <= a[i] + d && j < n){
            j++;
        }
        i = j;
        while(vis[i] && i > l) i--;
        if(i <= l) break;
        vis[i] = true;
        printf("%d\n", i);
        c2++;
    }
    if(c2 != c) return true;
    return false;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    scanf("%d %d", &c, &t);
    for(int T = 0; T < t; T++){
        int n, d;
        scanf("%d %d", &n, &d);
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            a[i] = x;
        }
        for(int i = 0; i < n - d; i++){
            for(int j = i + d + 1; j < n; j++){
                if(AAA(n, d, i, j)){
                    cp[T]++;
                    printf("%d %d\n", i, j);
                }
                for(int N = 0; N < n; N++) vis[i] = false;
            }
        }
    }
    for(int i = 0; i < t; i++){
        printf("%d\n", cp[i]);
    }
    return 0;
}
