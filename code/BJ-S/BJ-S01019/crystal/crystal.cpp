//所以万圣节到底等不等于圣诞节？
#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
int n;
long long m;
bool check(int l){
    for (int i = 1,j = l;j <= n;i++,j++) if (sum[j] - sum[i - 1] + m >= a[j] * l) return true;
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for (int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
    int l = 1,r = n;
    while (l < r){
        int mid = l + (r - l + 1 >> 1);
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
//本来只想先打平方暴力，结果突然发现不会打，但是能二分……代码比J2都短
/*
我是BJ-J01101！
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    freopen("crystal.in","w",stdout);
    freopen("crystal.out","r",stdin);
    //freopen("crystal,in"."r".stdin);
    //freopen("crystal,out"."w".stdout);
*/
