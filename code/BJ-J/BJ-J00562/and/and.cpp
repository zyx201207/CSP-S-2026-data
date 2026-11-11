#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    if(m == 1){
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }else if(m == n){
        int ans = a[1];
        for(int i = 1;i<=n;i++){
            ans = ans&a[i];
        }
        cout<<ans;
        return 0;
    }else if(m == n-1){
        int ans = 0;
        for(int i = 1;i<=n;i++){
            int cnt = -1;
            for(int j = 1;j<=n;j++){
                if(j == i){
                    continue;
                }
                if(cnt == -1){
                    cnt = a[j];
                }else{
                    cnt = cnt&a[j];
                }
            }
            if(ans < cnt){
                ans = cnt;
            }
        }
        cout<<ans;
        return 0;
    }else if(m == 2){
        int ans = 0;
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(i == j){
                    continue;
                }
                if(ans < a[i]&a[j]) ans = a[i]&a[j];
            }
        }
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    int ans = a[n];
    for(int i = 1;i<m;i++){
        ans = ans&a[n-i];
    }
    cout<<ans;
    return 0;
}