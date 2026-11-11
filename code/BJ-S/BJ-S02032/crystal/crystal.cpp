#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N];
long long b[N];//chazhi
int long n;
long long m;
long long ans = 1;
long long solve(int i){
    long long cnt = 1;
    long long k = 0;
    for(int j = i ;j>1;j--){
        k *= 2;
        k += b[j];
        if(k < 0) return cnt;
        if(m - k >= 0) cnt++;
    }
    return cnt;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
            cin >> a[i];
            b[i] = a[i] - a[i-1];
    }
    if(m == 0){
        sort(a+1,a+1+n);
        long long cnt = 1,ans = -1;
        for(int i = 2;i<=n;i++){
            if(a[i] == a[i-1]){
                cnt++;
            }else{
                ans = max(ans,cnt);
                cnt=1;
            }
        }
    }
    sort(a+1,a+1+n);
    for(int i = n;i>1;i--){
        ans = max(ans,solve(i));
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
