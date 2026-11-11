#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, m;
ll a[500005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int ans = 0;
    int pckpos = 1;
    for(int nowpos = 1;nowpos <= n;nowpos++){
        while(pckpos < nowpos && (nowpos-pckpos)*(a[nowpos]-a[nowpos-1]) > m){
            m += a[nowpos-1]-a[pckpos];
            pckpos++;
        }        
        ans = max(ans,nowpos-pckpos+1);
        m -= (nowpos-pckpos)*(a[nowpos]-a[nowpos-1]);
    }
    cout << ans;
    return 0;
}