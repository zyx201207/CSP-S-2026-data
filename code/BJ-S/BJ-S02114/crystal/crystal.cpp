#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 500005;
struct cnt{
    ll aa,cntaa = 0;
}cntans[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,mm = 0;
    ll m,a[MAXN],maxans = -1;
    cin>>n>>m;
    mm = m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        cntans[i].aa = a[i];
        cntans[i].cntaa++;
    }
    for(int i = n / 2 + 1;i <= n;i++){
        m = mm;
        for(int j = 1;j < i;j++){
            if(a[j] + m >= a[i] && m > 0){
                m -= a[j] - a[i];
            }
            else{
                break;
            }
            cntans[i].cntaa++;
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = i + 1;j <= n;j++){
            if(cntans[i].aa == cntans[j].aa){
                cntans[i].cntaa++;
            }
        }
        maxans = max(maxans,cntans[i].cntaa);
    }
    cout<<maxans<<endl;
    return 0;
}
