#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005],ans[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    b[1] = 0;
    ans[1] = 1;
    for(int i = 2;i <= n;i++){
        for(int j = i-1;j >= 1;j--){
            if(b[i]+a[i]-a[j]<=m){
                b[i]+=(a[i]-a[j]);
                ans[i]++;
            }
        }
    }
    long long maxx=-900000000000000;
    for(int i = 1;i <= n;i++){
        maxx = max(maxx,ans[i]);
    }
    cout<<maxx+1;
    return 0;
}
