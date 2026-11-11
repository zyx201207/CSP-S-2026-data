#include <bits/stdc++.h>
using namespace std;
int n,m,ans = 0;
const int P = 1 << 30;
int a[1 << 30];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    for (int i = 2;i <= n;i++){
        int h = a[i],c = 0;
        for (int j = 1;j <= n;j++){
            h = h & a[j];c++;
            if (c == m)
                if (h > ans){
                    ans = h;
                    break;
                }
                else
                    break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
