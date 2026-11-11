#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[2000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a + n + 1);
    printf("%d",a[n - m]);
}
