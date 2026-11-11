#include <bits/stdc++.h>
using namespace std;

const int N = 5e3+7;
int n,d,a[N],f[N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int p = 1;
    for(int i = 1;i<=n;i++){
        while(a[i]-a[p]>d){
            f[p] = i-p-1;
            p++;
        }
    }
    for(;p<=n;p++){
        f[p] = n-p;
    }
    printf("%d",f[1]);
    return 0;
}