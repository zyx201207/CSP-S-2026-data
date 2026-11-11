#include <bits/stdc++.h>
using namespace std;

long long a[100005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i ++){
        cin >> a[i];
    }
    long long ans = INT_MIN;
    if(m == 1){
        for(int i = 0;i < n;i ++){
            ans = max(ans,a[i]);
        }
    }
    else if(m == 2){
        for(int i = 0;i < n;i ++){
                for(int j = i+1;j < n;j ++){
                    ans = max(ans,(a[i]&a[j]));
            }
        }
    }
    cout << ans;
    return 0;
}
