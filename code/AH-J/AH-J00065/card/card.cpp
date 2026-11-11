#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+10;
ll n, m;
ll a[N];
vector <int> p[N];
int f[N],s[N];
int ans[N];
void solve(int q){
    f[a[q]]++;
    for(int i = 1;i <= m;i++)   s[i] = f[i];
    for(int i = q+1;i <= n;i++){
        if((p[a[i]].size()-1) == s[a[i]])  ans[a[i]]++;
        else
            s[a[i]]++, i = p[a[i]][s[a[i]]]-1;
    }
}
int main(){

  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        p[a[i]].push_back(i);
    }
    for(int i = 1;i <= n;i++){
        solve(i-1);
    }
    for(int i = 1;i <= m;i++)
        cout << ans[i] << ' ';
    return 0;
}
