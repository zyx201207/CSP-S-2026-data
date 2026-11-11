#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N];
long long sum[N];
bool cmp(long long a,long long b){
    return a < b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    unsigned long long m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i = 1;i <= n;i++){
        sum[i] = a[i]-a[i-1];
    }
    sum[1] = 0;
    long long ans = 0;
    unsigned long long cnt = 0,d = 0;
    long long r = 1;
    long long l = 1;
    while(r <= n && l <= n){
        if(cnt <= m && m > sum[r]){
            ans = max(ans,r-l+1);
            r++;
            cnt += sum[r]*(r-l);

        }else{
            cnt -= (a[r]-a[l]);
            l++;
        }
    }
    cout << ans;
    return 0;
}
