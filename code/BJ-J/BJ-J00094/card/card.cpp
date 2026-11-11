#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+10;
struct ac{
ll cnt;
vector<ll>v;
};
ll n,m,a[N];
map<ll,ll>ans;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    for (int i = 1;i <= n;i++){
        vector<ll>v;
        map<ll,ll>mm;
        ll cc=0;
        for (int j = i;j <= n;j++){

            if (a[mm[a[j]]]==a[j]){
                for (int q = mm[a[j]]+1;q < j;q++){
                    if (mm[a[q]]==q)mm[a[q]]=0;
                }
            }else {mm[a[j]]=j;v.push_back(a[j]);}
        }
        for (int j = 1;j <= m;j++){
            if (mm[j]!=0)ans[j]++;
        }
    }
    for (int i = 1;i <= m;i++){
        cout << ans[i] <<" ";
    }
    return 0;
}
