#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans = -1,sum,l,r;
bool flag(){
    for(int i = 1;i < n;i++){
        sum += a[n]-a[i];
    }
    return m >= sum;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if(flag()){
        if((m-sum)%n != 0) cout << n-1;
        else cout << n;
    }else{
        sum = 0;long long cnt = a[n]+1,f = n;
        while(cnt--){
            long long i = n,num = m;
            if(a[f] > cnt && a[f-1] <= cnt) f--;
            while(num >= 0 && i >= 1){
                i--;
                if(a[i] > cnt) continue;
                num -= cnt-a[i];
            }
            i++;
            if(f-i+1 > ans) ans = f-i+1;
        }
        cout << ans;
    }
    return 0;
}
