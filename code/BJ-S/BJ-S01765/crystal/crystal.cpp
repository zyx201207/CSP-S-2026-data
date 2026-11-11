#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n + 1];
    long long cnt  = 0;
    long long maxn = 0;
    long long maxm = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        cnt += a[i];
        if((m + cnt + i - 1) / i >= a[i]){
            maxn = i;
        }
    }
    cout<<maxn;
}
