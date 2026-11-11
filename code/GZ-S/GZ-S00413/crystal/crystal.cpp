//GZ-S00413 黔南州布依族苗族自治州都匀第一中学 邹佳航
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 5e5 + 5;

int n;
ll m,ans = 0,cnt = 0,c = 0;
ll a[MAXN];
bool is_d = 0;
ll dcsl = 0;

bool cmp(ll a,ll b){
    return a > b;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n,cmp);
    if(n<=5000){

        for(int i = 1;i<=n;i++){
            cnt = 0;
            c = 0;
            for(int j = i;j<=n;j++){
                if(cnt + abs(a[i] - a[j]) <= m){
                    cnt += abs(a[i] - a[j]);
                    c++;
                }
            }
            ans = max(ans,c);
        }

    }
    else{
        dcsl = a[2] - a[1];
        is_d = 1;
        for(int i = 2;i<=n;i++){
            if(a[i] - a[i-1] == dcsl) continue;
            is_d = 0;
        }
        ans = 1;
        for(int i = 1;i<=n;i++){
            if(cnt + (i * dcsl) <= m){
                cnt += i * dcsl;
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
