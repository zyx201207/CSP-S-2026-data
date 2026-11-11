#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int i = 1;
    long long cur = 0;
    while(true){
        cur = (a[i+1]-a[i])*i;
        if(m - cur < 0) break;
        else{
            m -= cur;
            i++;
        }
    }
    int cnt = 1;
    for(int j = i+2;j <= n;j++){
        if(a[j]!=a[i+1]) break;
        cnt++;
    }
    int ans2 = cnt+m/(a[i+1]-a[i]);
    cout << max(ans2,i);
    return 0;
}

