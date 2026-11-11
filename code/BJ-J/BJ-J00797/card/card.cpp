#include<bits/stdc++.h>
using namespace std;
int n, m, a[5005], cnt[5005];
bool A = 1;
map<int, int> mp;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
        if(a[i] < a[i - 1]) A = 0;
    }
    if(m == 2){
        for(int i = 1; i <= n; i++)
            if(a[i] == a[n]) cnt[a[n]]++;
            else cnt[a[i]]++, cnt[a[n]]++;
        printf("%d %d", cnt[1], cnt[2]);
    }
    else if(A){
        for(int i = 1; i <= n; i++) mp[a[i]]++;
        for(int i = 1; i <= m; i++) cnt[i] = cnt[i - 1] + mp[i];
        for(int i = 1; i <= m; i++) printf("%d ", cnt[i]);
    }
}
