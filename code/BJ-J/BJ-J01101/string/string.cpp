#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1;i <= n;i++){
        int x;
        char gunmu;
        cin >> x >> gunmu;
        if (gunmu == c[cnt]) a[cnt] += x;
        else {
            a[++cnt] = x;
            c[cnt] = gunmu;
        }
    }
    n = cnt;
    cnt = 0;
    long long ans = 0;
    for (int i = 1,j = n;i < j;){
        long long knockdown = min(a[i],a[j]);
        if (c[i] != c[j]) ans += knockdown;
        a[i] -= knockdown;
        a[j] -= knockdown;
        if (!a[i]) i++;
        if (!a[j]) j--;
    }
    cout << ans << endl;
    return 0;
}
/*
为什么我在编译器上画词显示的是英英释义而不是定义使用方法啊？

//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
freopen("travel.in","w",stdin);
freopen("travel.out","r",stdout);
freopen("travel,in"."w".stdout);
freopen("travel,out"."r".stdin);


*/
