#include <bits/stdc++.h>
using namespace std;
int n,a[200001],ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1;i <= n;i++){
        scanf("%d",a[i]);
        ans += a[i];
    }
    printf("%d",ans / 2);
    return 0;
}
