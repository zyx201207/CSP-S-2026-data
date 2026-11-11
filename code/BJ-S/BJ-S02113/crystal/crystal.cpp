#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+8;

int n,m,a[N],dif[N];

int pre[N];

bool flag = 1;
signed main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    int maxn = -1e12;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);

    int tmp = a[2]-a[1];
    for(int i = 1; i < n; i++){
        if(a[i+1]-a[i] != tmp) flag = 0;
    }
    if(flag){
        for(int i = 2; i <= n; i++){
            dif[i] = dif[i-1]+(i-1)*tmp;
        }
        //for(int i = 1; i <= n; i++) cout << dif[i] << " ";
        //cout << endl;
        //for(int i = 1; i <= n; i++) cout << dif[i] <<" ";
        cout << upper_bound(dif+1,dif+n+1,m)-dif-1;
        return 0;
    }
    for(int i = 1; i <= n; i++) pre[i] = pre[i-1]+a[i];
    dif[1] = 0;
    for(int i = 2; i <= n; i++){
        dif[i] = a[i]*(i-1) - pre[i-1];
    }

    //for(int i = 1; i <= n; i++) cout << dif[i] << " ";

    //cout << endl;
    cout << upper_bound(dif+1,dif+n+1,m)-dif-1;
    return 0;
}
