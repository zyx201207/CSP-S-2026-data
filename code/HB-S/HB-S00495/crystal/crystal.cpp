#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;

long long a[MAXN];

bool cmp(int a,int b){
    return a > b;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    long long n, m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> a[i];

    }
    int temp = a[n] - a[n-1];
    int ans = 0,sum = 0;
    for(long long i = 0;i<=m;i+=temp){
        i += sum;
        sum ++;
        ans ++;
    }
    sort(a+1,a+1+n);
    cout << ans;
}
