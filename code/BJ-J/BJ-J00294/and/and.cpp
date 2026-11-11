#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    int ans = 0;
    if(m == 1){
        for(int i = 1;i <= n;i++){
            ans = max(ans,a[i]);
        }
        printf("%d",ans);
    }else if(m == 2){
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                ans = max(ans,(a[i] & a[j]));
            }
        }
        printf("%d",ans);
    }else if(m == n){
        ans = a[1];
        for(int i = 1;i <= n;i++){
            ans = (ans & a[i]);
        }
        printf("%d",ans);
    }else if(m == n - 1){
        for(int i = 1;i <= n;i++){
            int ans2 = 0;
            for(int j = 1;j <= n;j++){
                if(i == 1){
                    ans2 = a[2];
                }else{
                    ans2 = a[1];
                }
                if(j != i){
                    ans2 = (ans2 & a[j]);
                }
            }
            ans = max(ans,ans2);
        }
        printf("%d",ans);
    }else{
        sort(a + 1,a + n + 1);
        ans = a[n];
        for(int i = n;i >= n - m + 1;i--){
            ans = (ans & a[i]);
        }
        printf("%d",ans);
    }
    return 0;
}
