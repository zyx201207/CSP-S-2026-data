#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,maxx,ans;
ll a[200005];
bool visit[25];
void dfs(int step,ll tmp){
    if(step == m){
        ans = max(ans,tmp);
        return;
    }
    for(int i = 0;i < n;i++){
        if(visit[i] == 0){
            visit[i] = 1;
            ll tmp1;
            tmp1 = tmp & a[i];
            dfs(step+1,tmp1);
            tmp1 = tmp;
            visit[i] = 0;
        }
    }
    return;
}
bool cmp(ll a,ll b){
    return a > b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++)cin >> a[i];
    if(m == 1){
        for(int i = 0;i < n;i++){
            maxx = max(maxx,a[i]);
        }
        cout << maxx;
        return 0;
    }
    if(m == n){
            ans = a[0];
        for(int i = 1;i < n;i++){
            ans = ans & a[i];
        }
        cout << ans;
        return 0;
    }
    if(m == 2 && n <= 5000){
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                ans = max(ans,a[i] & a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    if(n <= 100){
        dfs(0,-1);
        cout << ans;
    }
    sort(a,a+n,cmp);
    cout << a[m-1];
    return 0;
}
