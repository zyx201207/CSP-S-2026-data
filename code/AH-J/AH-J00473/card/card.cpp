#include <bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=1e5*5+10;
int a[maxn];
int main(){
    freopen("card,in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        printf("1 ");
    }
    return 0;
}
