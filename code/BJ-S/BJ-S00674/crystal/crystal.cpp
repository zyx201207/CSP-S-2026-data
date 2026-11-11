#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
using namespace std;
int n;
ll m;
int ans;
ll a[500010];
ll b[500010];
ll p[500010];
bool cmp(ll a1,ll a2){
    return a1 < a2;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i = 1;i < n; i++){
        b[i] = a[i+1]-a[i];
        p[i] = p[i-1] + b[i];
    }
    int cl = 1,cr = 1;
    ll sum = 0;
    while(cr < n && cl <= cr){
        if(sum <= m){
            ans = max(ans,cr-cl+1);

            sum += b[cr] * (cr-cl+1);
            cr++;
        }else{
            sum -= p[cr] - p[cl];
            cl++;
        }
        //cout << cl << ' ' << cr << ' ' <<sum << '\n';
    }
    cout << ans;
    return 0;
}
