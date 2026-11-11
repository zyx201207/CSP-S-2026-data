#include<iostream>
using namespace std;

long long ans;
int a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i] >> c[i];
    int l = 1,r = n;
    while(l < r){
        if(c[l] == c[r]){
            if(a[l] > a[r]) a[l] -= a[r],r--;
            else if(a[r] > a[l]) a[r] -= a[l],l++;
            else l++,r--;
        }
        else if(c[l] != c[r]){
            if(a[l] > a[r]) a[l] -= a[r],ans += a[r],r--;
            else if(a[r] > a[l]) a[r] -= a[l],ans += a[l],l++;
            else l++,r--,ans += a[l];
        }
    }
    cout << ans;
    return 0;
}

