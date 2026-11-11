#include <bits/stdc++.h>
using namespace std;
int a[200005],l,r;
char a_[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> a[i] >> a_[i];
    }
    long long ans = 0;
    r = n - 1;
    while(1){
        if(a_[l]!=a_[r]){
            ans+=min(a[l],a[r]);
        }
        if(a[l] == a[r]){
            l++;
            r--;
        }else if(a[l] > a[r]){
            a[l]-=a[r];
            r--;
        }else{
            a[r]-=a[l];
            l++;
        }
        if(l >= r){
            break;
        }
    }
    cout << ans;
    return 0;
}
