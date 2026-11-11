#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5+7;
struct node{
    int sum;
    char zf;
}a[maxn];
node z[maxn],y[maxn];
int n;
int hfsum;
int cntz,cnty;
int zsum,ysum;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i].sum >> a[i].zf,hfsum += a[i].sum;
    if (hfsum%2 == 0) hfsum /= 2;
    else hfsum = (hfsum-1)/2;
    for (int i = 1;i <= n;i++){
        if (zsum+a[i].sum <= hfsum){
            zsum += a[i].sum;
            if (a[i].zf == z[cntz].zf) z[cntz].sum += a[i].sum;
            else z[++cntz] = a[i];
        }
        else{
            if (hfsum-zsum == 0) break;
            int sy = hfsum-zsum;
            char zf = a[i].zf;
            zsum += sy;
            if (zf == z[cntz].zf) z[cntz].sum += sy;
            else z[++cntz] = {sy,a[i].zf};
            break;
        }
    }
    for (int i = n;i >= 1;i--){
        if (ysum+a[i].sum <= hfsum){
            ysum += a[i].sum;
            if (a[i].zf == y[cnty].zf) y[cnty].sum += a[i].sum;
            else y[++cnty] = a[i];
        }
        else{
            if (hfsum-ysum == 0) break;
            int sy = hfsum-ysum;
            char zf = a[i].zf;
            ysum += sy;
            if (zf == y[cnty].zf) y[cnty].sum += sy;
            else y[++cnty] = {sy,a[i].zf};
            break;
        }
    }
    int ans = 0;
    for (int i = 1,j = 1;i <= cntz,j <= cnty;i++){
        while (z[i].sum != 0){
            if (j > cnty) break;
            if (z[i].zf != y[j].zf){
                if (z[i].sum >= y[j].sum){
                    ans += y[j].sum;
                    z[i].sum -= y[j].sum;
                    y[j].sum = 0;
                    j++;
                    continue;
                }
                else{
                    ans += z[i].sum;
                    y[j].sum -= z[i].sum;
                    z[i].sum = 0;
                }
            }
            else{
                if (z[i].sum >= y[j].sum){
                    z[i].sum -= y[j].sum;
                    y[j].sum = 0;
                    j++;
                    continue;
                }
                else{
                    y[j].sum -= z[i].sum;
                    z[i].sum = 0;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
