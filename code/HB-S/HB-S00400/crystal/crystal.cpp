#include<bits/stdc++.h>
using namespace std;
int n , ans;
long long a[50000005] , m, num , b[50000005];
int main()
{
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1 , a+n+1);
    if(a[n] == 0){
        if(m < n)
            ans = m;
        else ans = n;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= i;j++){
            b[i] += a[i] - a[j];
        }
        if(b[i] > m){
            ans = i - 1;
            break;
        }
    }
    cout << ans;
    return 0;
}

