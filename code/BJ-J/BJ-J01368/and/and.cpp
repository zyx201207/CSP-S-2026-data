#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
int a[N];
int n,m;
int maxn = -1;

void and(int k,int sum){
    if(k == 0) {
        maxn = max(maxn,sum);
        return ;
    }
    for(int i = 1; i <= n; i++){
        if(k == m) sum = a[i];
        else sum &= a[i];
        and(k - 1,sum);
    }
}

signed main(){
    freopen("and.in",stdin,"r");
    freopen("and.out",stdout,"w");

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    and(m,0);
    cout << maxn << endl;
    return 0;
}