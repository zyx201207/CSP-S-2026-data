#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int a[N],ans;
//ten to two
int ttt(int t){
    int n = 1,ans = 0;
    while(t){
        ans += t%2*n;
        n*=10;
        t/=2;
    }
    return ans;
}
//two back to ten
int tbt(int t){
    int n = 1,ans = 0;
    while(t){
        ans+=t%10*n;
        t/=10;
        n*=2;
    }
    return ans;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >>m;
    for(int i = 0;i<n;i++){
        cin >> a[i];
    }
        int maxn = -1;
        for(int i = 0;i<n;i++){
            if(maxn<a[i]){
                maxn = a[i];
            }
        }
        cout << maxn;
    return 0;
}
