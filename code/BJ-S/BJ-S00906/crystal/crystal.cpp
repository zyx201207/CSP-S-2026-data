#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500007],ans=1;
ll b[500007],c[500007];
bool check(ll d,ll e){
    if(c[e]-c[d-1] <= m)
        return 1;
    else return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(ll i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    if(n>1500){
        for(int i=1;i<=n;i++){
            if((1+i)*i*(a[2]-a[1])>m){
                cout << 2*i-1;
                return 0;
            }
        }
    }
    ll num1 = a[(n+1)/2];
    for(ll i=1;i<=n;i++)
        b[i] = a[i]-num1;
    for(ll i=1;i<=n;i++){
        ll num2 = num1-a[i];
        for(ll j=1;j<=n;j++)
            c[j] = c[j-1]+abs(b[j]+num2);
        for(ll x=1;x<=n;x++)
            for(ll y=x+1;y<=n;y++)
                if(check(x,y))
                    ans = max(ans,y-x+1);
    }
    cout << ans;
    return 0;
}
