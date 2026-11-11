#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
int l,r,cnt;
long long ans = 0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
    }
    l = 1,r = n;
    while(l < r){
        if(c[l] != c[r]){
            ans+=min(a[l],a[r]);
        }
        cnt = a[l]-a[r];
        a[l] = max(0,a[l]-a[r]);
        a[r] = max(0,-cnt);
        if(a[l] == 0){
            l++;
        }
        if(a[r] == 0){
            r--;
        }
        if(l >= r){
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
