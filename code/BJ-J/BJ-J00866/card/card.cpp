#include<iostream>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n,m,a[N + 1],last[N + 1],cnt[N + 1],ans[N + 1];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
        cin>>a[i],last[a[i]] = i,cnt[i] = 1;
    for(int i = 1;i <= n;i++)
        ans[a[i]] += cnt[i],cnt[last[a[i]] + 1] += cnt[i];
    for(int i = 1;i <= m;i++)
        cout<<ans[i]<<" ";
}
