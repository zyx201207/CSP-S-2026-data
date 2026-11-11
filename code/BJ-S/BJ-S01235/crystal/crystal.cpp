#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n,m,a[N],b[N],c[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
        b[i] = a[i]-a[i-1];
    long long sum = 0,ans = 0,len;
    long long l = 1,r = 1;
    while(r != n){
        if(sum <= m){
            len = r-l+1;
            ans = max(ans,len);
            if(sum + len*b[r+1] <= m){
                r++;
                sum += len*b[r];
            }
            else if(l == r){
                l++;
                r++;
                sum = 0;
            }
            else{
                l++;
                sum -= a[r]-a[l];
            }
        }
    }
    cout << ans;
    return 0;
}
