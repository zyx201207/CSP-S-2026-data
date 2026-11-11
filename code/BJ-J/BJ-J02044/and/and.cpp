#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[200010],b[200010],ans,ans2;
int get(int x){
    int cnt = 0;
    while(x){
        if(x % 2 == 1){
            cnt++;
        }
        x /= 2;
    }
    return cnt;
}
bool cmp(int x, int y){
    int p = get(x), q = get(y);
    if(x > y){
        return true;
    }
    if(x == y){
        if(p >= q){
            return true;
        }
    }
    return false;
}
bool cmp2(int x, int y){
    int p = get(x), q = get(y);
    if(p > q){
        return true;
    }
    if(p == q){
        if(x >= y){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp2);
    ans = a[1];
    ans2 = b[1];
    for(int i = 2;i <= m;i++){
        ans &= a[i];
        ans2 &= b[i];
    }
    printf("%d\n",max(ans,ans2));
    return 0;
}
