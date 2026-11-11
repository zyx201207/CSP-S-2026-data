#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int le[1000005];
int cnt[500005];
int r;
inline void pop(int x){
    bool f = false;
    for(int i = 1;i <= r;i++){
        if(le[i] == x){
            r = i;
            f = true;
            break;
        }
    }
    if(!f){
        le[r + 1] = x;
        r++;
    }
    //printf("pop %d,",x);
}
inline void game(int i){
    r = 0;
    memset(le,0,sizeof(le));
    for(int x = i;x <= n;x++){
        pop(a[x]);
        //printf("left:");
        //for(int y = 1;y <= r;y++){
            //printf("%d ",le[y]);
        //}
        //printf("\n");
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        //printf("now i = %d,input a[i] = %d\n",i,a[i]);
    }
    for(int i = 1;i <= n;i++){
        game(i);
        //printf("in the %d round,left:",i);
        for(int i = 1;i <= r;i++){
            cnt[le[i]]++;
            //printf("%d ",le[i]);
        }
        //printf("\n");
    }
    for(int i = 1;i <= m;i++){
        cout << cnt[i] << ' ';
    }
    return 0;
}
