#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans;
int aaaa = 1073741823;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    if(n == m){
            ans = a[1];
        for(int i = 2;i<=n;i++){
            ans &= a[i];
        }
    }else if(m == 1){
        for(int i = 1;i<=n;i++){
            ans = max(ans,aaaa & a[i]);
        }
    }else if(m == 2){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(i == j) continue;
                ans = max(ans,a[i] & a[j]);
            }
        }
    }
    cout<<ans;
    return 0;
}
