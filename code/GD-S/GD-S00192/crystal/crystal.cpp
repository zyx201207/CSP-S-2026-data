#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define fr(a,b,c) for(int a = (b);a <= (c);a ++)
using namespace std;
const int N = 600000;
int n,ans,it;
ll m,a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    fr(i,1,n) cin >> a[i];
    sort(a + 1,a + n + 1);
    fr(i,1,n) s[i] = s[i - 1] + a[i];
    fr(i,1,n){
      if((i - it) * a[i] - (s[i] - s[it]) > m) it ++;
      ans = max(ans,i - it);
    }
    printf("%d\n",ans);
    return 0;
}
