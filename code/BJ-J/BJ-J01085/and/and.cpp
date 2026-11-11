#include<bits/stdc++.h>
using namespace std;
long long a[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long sum;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    sum=a[n];
    for(int i=n;i>=n-m+1;i--){
        sum=(sum&a[i]);
    }
    cout << sum;
    return 0;
}
