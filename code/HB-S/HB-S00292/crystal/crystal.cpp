#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt,maxn,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        ans = 1;
        cnt = 0;
        for(int j=0;j<n;j++){
            if(a[j]>a[i] || i==j) continue;
            cnt += a[i]-a[j];
            if(cnt > m){
                break;
            }
            ans++;
        }
        maxn = max(maxn,ans);
    }
    cout << maxn;
    return 0;
}
