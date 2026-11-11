#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans = 0;
    cin >> n;
    long long a[200005];
    long long sum[200005];
    sum[0] = 0;
    char c[200005];
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
        sum[i] = sum[i-1] + a[i];
    }
    int j1 = 0, j2 = n - 1, l = 1;
    for(long long i = 1;i <= sum[n]/2;i += max(1,l)){
        while(!(sum[j1] < i && sum[j1+1] >= i)) j1++;
        while(!(sum[j2] < (sum[n] + 1 - i) && sum[j2+1] >= (sum[n] + 1 - i))) j2--;
        l = min((sum[j1+1] - i + 1),((sum[n] - i + 1) - sum[j2]));
        if(c[j1+1] != c[j2+1]) ans+=l;
    }
    cout << ans;
    return 0;
}
