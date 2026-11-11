#include <bits/stdc++.h>
using namespace std;
long long a[50005],q[50005],fd[5005][5005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,ans = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        q[i] = a[i] - a[i - 1];
    }
    if(n > 5000){
        int l = abs(a[1] - a[2]);
        int sam = 0;
        for(int i = 1;i < n;i++){
            sam+=(i*l);
            if(sam > m){
                cout << i;
                return 0;
            }
        }
        cout << n;
        return 0;
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        for(int j = i;j >= 1;j--){
            fd[j][i] = fd[j][i-1] + q[i];
            if(i == j){
               fd[j][i] = 0;
            }
        }
    }
    int sum = 0;
    for(int i = 1;i <= n;i++){
        for(int j = i;j >= 1;j--){
            sum+=fd[j][i];
            if(sum > m){
                ans = max(ans,j-1);
                break;
            }
            if(j == 1){
                ans = max(ans,j);
            }
        }

    }
    cout << ans;
    return 0;
}
/*#include <bits/stdc++.h>
using namespace std;
long long a[500005],q[500005];
int main(){
    freopen("crystal3.in","r",stdin);
    long long n,m,ans = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        q[i] = a[i] - a[i - 1];
    }
    sort(a + 1,a + n + 1);
    long long jc = 0,couj = n;
    for(int i = n;i >= 1;i--){
        long long sam = jc,cou = i - couj,sam2 = 0;
        for(int j = couj;j >= 1;j--){
            sam2+=q[j + 1];
            sam+=sam2;
            if(sam > m){
                break;
            }
            jc = sam - cou * q[i] + q[i];
            cou++;
        }
        couj = i - cou;
        cout << cou << ' ';
        ans = max(ans,cou);
    }
    cout << ans;
    return 0;
}*/
/*#include <bits/stdc++.h>
using namespace std;
long long a[500005],q[500005];
int main(){
    freopen("crystal3.in","r",stdin);
    long long n,m,ans = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        q[i] = a[i] - a[i - 1];
    }
    sort(a + 1,a + n + 1);
    long long e = 2,jc = 0,couj = n;
    for(int i = n;i >= e;i--){
        long long sam = jc,cou = i - couj + 1,sam2 = 0;
        for(int j = couj;j >= e;j--){
            sam2+=q[j + 1];
            sam+=sam2;
            if(sam > m){
                break;
            }
            jc = sam - cou * q[i];
            cou++;
        }
        e = max(e,cou);
        couj = i - cou;
        ans = max(ans,cou);
        if(couj <= 0){
           break;
        }
    }
    cout << ans;
    return 0;
}*/
//用于后续研究的失败程序
