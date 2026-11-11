#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int a,int b){
    return a >b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long ans = 0;
    cin >> n >>m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    for (int i = 1;i <= m;i++){
        if (ans)
            ans = a[i]&ans;
        else{
            ans = a[i];
        }
    }
    cout << ans;
    return 0;
}
