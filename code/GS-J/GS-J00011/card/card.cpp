#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],pos[300005],rev[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
    for(int i = 1;i <= n;i++){//turn
        int r = 0;
        for(int j = i;j <= n;j++){//each of card (id)
            r++;//this]
            if(pos[a[j]] != 0 && pos[a[j]] < r) r = pos[a[j]];
            pos[a[j]] = r;
            rev[r] = a[j];//time
        }
        for(int j = 1;j <= m;j++){
            if(pos[j] != 0 && pos[j] <= r && rev[pos[j]] == j) t[j]++;
            pos[j] = 0;
        }
    }
    for(int i = 1;i <= m;i++) printf("%d ",t[i]);
    return 0;
}
