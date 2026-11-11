#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN = int(5e5)+5;

int n,m;
int a[MAXN];
int s[MAXN];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    s[0] = 0;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for(int i = 1;i<=n;i++){
        s[i] = s[i-1]+a[i];
    }
    int t = -1;
    for(int L = 1;L<=n;L++){
        int ans = 0;
        int l = 1,r = L;
        while(l <= r){
            int mid = (l+r)/2;
            if(a[L]*mid-(s[L]-s[max(L-mid,0)]) <= m){
                ans = mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        // cout << ans << " " << a[L] << " " << s[L]-s[max(L-ans,0)] << endl;
        t = max(t,ans);
    }
    cout << t << endl;
    return 0;
}