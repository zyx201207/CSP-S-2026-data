#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m,a[214514],ans;
bool cmp(int x,int y){
    return x > y;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    /*for(int i = 1;i <= n;i++){
        cout << a[i];
    }*/
    //cout << endl;
    ans = a[1];
    for(int i = 1;i <= m;i++){
        ans = ans & a[i];
    }
    cout << ans;
    return 0;
}
