#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;

int a[N];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,ans = 0;                //m 表示至多操作次数
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for(int mid = 1;mid<=n;mid++){
        int sum = 0;
        for(int i = mid-1;i>=1;i--){
            m-=(a[mid]-a[i]);
            if(m < 0){
                break;
            }
            a[i] = a[mid];
        }
        for(int i = 1;i<=n;i++){
            if(a[i] == a[mid]){
                sum++;
            }
        }
        ans = max(ans,sum);
    }
    cout << ans;
    return 0;
}
