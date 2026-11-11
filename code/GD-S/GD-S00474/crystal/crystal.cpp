#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,m,a[N],diff[N],pre[5005][5005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i = 1;i<=n;i++) diff[i] = a[i]-a[i-1];
    if(n>5000 && m>1e18){
        int i = 1,mult = 1;
        while(true){
            if(mult*diff[2] > m){
                cout<<i;
                return 0;
            }
            i++;
            mult+=i;
        }
    }
    for(int i = 1;i<=n;i++){
        pre[i][i] = diff[i];
        for(int j = i+1;j<=n;j++){
            pre[i][j] = pre[i][j-1] + (j-i+1)*diff[j];
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        int it = upper_bound(pre[i+1]+i+1,pre[i+1]+n+1,m)-pre[i+1]-1;
        ans = max(ans,it-i+1);
    }
    cout<<ans;

    return 0;
}