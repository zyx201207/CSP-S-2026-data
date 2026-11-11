#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n,a[N],ans = 0;
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 0;i<n;i++){
        char c;
        cin >> a[i] >> c;
        s+=c;
    }
    int l = 0,r = n-1;
    while(l<r){
        if(s[l]==s[r]){
            if(a[l]>a[r]){
                a[l] = a[l]-a[r];
                r--;
            }else if(a[l]<a[r]){
                a[r] = a[r]-a[l];
                l++;
            }else{
                l++;
                r--;
            }
        }else{
            if(a[l]>a[r]){
                ans+=a[r];
                a[l] = a[l]-a[r];
                r--;
            }else if(a[l]<a[r]){
                ans+=a[l];
                a[r] = a[r]-a[l];
                l++;
            }else{
                ans+=a[l];
                l++;
                r--;
            }
        }
    }
    cout << ans;
    return 0;
}
