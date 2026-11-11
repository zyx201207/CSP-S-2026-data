#include <bits/stdc++.h>
using namespace std;
#define MAXN 625001
typedef long long ll;
ll a[MAXN],f[MAXN],m;
int n,ans=0;
bool cmp(ll a,ll b){
    return a<b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a+1,a+n+1,cmp);     
    f[1]=0;
    int sum=1;
    for(int i = 2;i <= n;i++){
        ll d=a[i]-a[i-1];
        ll op=1LL*f[i-1]+1LL*d*(i-1);
        if(d==0){
            sum++;
            ans=max(ans,sum);
            f[i]=f[i-1];
        }
        else if(op<=m){
            f[i]=op;
            sum++;
            ans=max(ans,sum);
        }
        else{
            f[i]=0;
            sum=1;
        }
    }
    cout << ans;
    return 0;
}