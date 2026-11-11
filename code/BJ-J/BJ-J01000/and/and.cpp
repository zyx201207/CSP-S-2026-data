#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
int n,m,ans;
ll a[maxn];
void dfs(int maxi,int x,int num){
    //cout << maxi - 1 << ' ' <<  x - 1<< ' ' << num << ' ' << ans << endl;
    if(x > m){
        ans = max(ans,num);
        //cout << maxi << ' ' <<  x << ' ' << num << ' ' << ans << endl;
        return ;
    }
    for(int i = maxi + 1;i + (m - x) <= n;i++){
        if(x == 1)dfs(i,x + 1,a[i]);
        else dfs(i,x + 1,num & a[i]);
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dfs(0,1,0);
    cout << ans;
    return 0;
}
