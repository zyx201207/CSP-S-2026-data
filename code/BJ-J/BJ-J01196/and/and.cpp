#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N],s[N],si,n,m,A,B,C,ans;
void dfs(int depth){
    if(si > m) return;
    if(depth == n+1){
        if(si != m) return;
        int xx = s[1];
        for(int i = 2;i <= si;i++){
            xx = xx&s[i];
        }
        ans = max(ans,xx);
        return;
    }
    s[++si] = a[depth];
    dfs(depth+1);
    s[si] = 0;
    si--;
    dfs(depth+1);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(a[i] >= 4) C = 1;
        if(a[i] != i-1) B = 1;
    }
    if(n <= 20){
        dfs(1);
        cout << ans << endl;
    }
    else if(n <= 2000){
        if(m == 1){
            for(int i = 1;i <= n;i++) ans = max(ans,a[i]);
        }
        else if(m == 2){
            for(int i = 1;i <= n;i++){
                for(int j = i+1;j <= n;j++){
                    ans = max(ans,a[i]&a[j]);
                }
            }
        }
        else if(m == n){
            ans = a[1];
            for(int i = 2;i <= n;i++) ans = ans&a[i];
        }
        cout << ans << endl;
    }
    else if(m == n-1){
        sort(a+1,a+1+n);
        ans = a[2];
        for(int i = 3;i <= n;i++)
            ans = ans&a[i];
        cout << ans << endl;
    }
    else if(B == 0){
        ans = n-1;
        for(int i = n-m;i <= n-1;i++)
            ans = ans&i;
        cout << ans << endl;
    }
    else{
        sort(a+1,a+1+n);
        ans = a[n-m+1];
        for(int i = n-m+1;i <= n;i++)
            ans = ans&a[i];
        cout << ans << endl;
    }


    return 0;
}
