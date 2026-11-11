#include<bits/stdc++.h>
#define int long long
using namespace std;
struct p{int num,su;}a[200086] = {};
bool cmp(p a,p b){
    if(a.su != b.su)return a.su < b.su;
    return a.num < b.num;
}
int e(int l){
    int su = 0;
    while(l > 0){
        if(l % 2)su++;
        l /= 2;
    }
    return su;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,an;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i].num;
        a[i].su = e(a[i].num);
    }
    sort(a + 1,a + n + 1,cmp);
    an = a[n - m + 1].num;
    for(int i = n - m + 1;i <= n;i++)an &= a[i].num;
    cout << an;
    return 0;
}
//快来看我的雷霆猪爆球塞T4吧
