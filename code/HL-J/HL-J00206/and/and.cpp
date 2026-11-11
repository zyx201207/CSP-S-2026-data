#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 * 2 + 5;
int n,m;
long long a[N],ans1 = 0,q,ans2 = 0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    for (int i = 1;i <= n;i ++){
        if (a[i] > ans1){
            ans1 = a[i];
            q = i;
        }
    }
    for (int i = 1;i <= n;i ++){
        if (a[i] > ans2 || i != q){
            ans2 = a[i];
        }
    }
    cout << ans2;
}
