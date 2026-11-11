#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;
long long sum[MAXN],arr[MAXN];
long long m;
long long sumval;
int n;
int ans;

int bs(int l,int r){
    int bsans = -1;
    int rangel = l,ranger = r;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(sum[ranger] - sum[mid - 1] - ((long long) (ranger - mid + 1)) * sumval <= m){
            bsans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return bsans;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
    }
    sort(arr + 1,arr + n + 1);
    for(int i = 1;i<n;i++){
        sum[i] = arr[n] - arr[i];
        sum[i] += sum[i - 1];
    }
    for(int r = n;r>=2;r--){
        int bsans = bs(1,r - 1);
        if(bsans == -1){
            ans = max(ans,1);
        }else{
            ans = max(ans,r - bsans + 1);
        }
        sumval += arr[r] - arr[r - 1];
    }
    ans = max(ans,1);
    cout << ans;
    return 0;
}
