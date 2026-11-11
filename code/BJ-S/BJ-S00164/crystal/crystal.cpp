#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
int n;
long long m,a[maxn],presum[maxn];
int ans = 0;
bool check(int pos,int nw){
    long long res;
    res = (long long)a[nw] * (long long)(nw - pos + 1) - presum[nw] + presum[pos - 1];
    if(res <= m){
        return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        presum[i] = presum[i - 1] + a[i];
        //cout << presum[i] <<" ";
    }
    //cout << endl;
    for(int i = 1;i <= n;i++){
        int l = 1,r = n;
        while(l + 1 < r){
            int mid = (l + r) >> 1;
            if(check(mid,i)){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        if(check(l,i)){
            r = l;
        }
        int len = i - r + 1;
        ans = max(ans,len);
    }
    cout << ans << endl;
    return 0;
}
