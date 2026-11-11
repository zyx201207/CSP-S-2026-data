#include<bits/stdc++.h>
using namespace std;

long long int  n, m = 0, y,k;
long long int a[500001], x[500001] ;

int main(){
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[n]);
    }
    for(int j = 1; j <= k; j++){
    if(a[n + 1] >= a[n]){
        x[j] = a[n + 1] - a[n];
     if(x[j] + x[j + 1] == m){
        y += 1;
     }

        }
    }
    printf("%lld", y);

return 0;
}
