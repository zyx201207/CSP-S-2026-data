#include <bits/stdc++.h>
using namespace std;

int n,m = 0,sum = 0;
int a[5000005],c[5000005],top = 0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1;i <= m;i++){
        printf("%d",i);
    }
    return 0;
}
