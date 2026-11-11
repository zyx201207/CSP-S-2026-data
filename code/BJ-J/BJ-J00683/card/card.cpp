#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],d[500010],top,arr[500010];
long long ans[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            if(arr[a[j]] != 0){
                for(int k = arr[a[j]]+1;k <= top;k++) arr[d[k]] = 0;
                top = arr[a[j]];
            }else{
                d[++top] = a[j];
                arr[a[j]] = top;
            }
        }
        for(int k = 1;k <= top;k++) ans[d[k]]++;
        top = 0;
        for(int k = 1;k <= m;k++) arr[k] = 0;
    }
    for(int i = 1;i <= m;i++) cout << ans[i] <<" ";
    return 0;
}
