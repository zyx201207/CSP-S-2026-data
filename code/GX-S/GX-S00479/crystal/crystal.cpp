#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5+5;
ll read(){
    char x = getchar();
    ll a = 1,ans = 0;
    while(x < '0'||x > '9'){
        if(x == '-')a = -1;
        x = getchar();
    }
    while(x >= '0'&&x <= '9'){
        ans = ans*10+x-'0';
        x = getchar();
    }
    return ans*a;
}
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n = read(),m = read();
    ll suml = 0;
    for(int i = 1;i <= n;i ++){
        a[i] = read();
    }
    sort(a+1,a+1+n);
    ll l = 1,ans = 0;
    for(int i = 1;i <= n;i ++){
        if(i != 1){
            suml += (i-l)*(a[i]-a[i-1]);
        }
        while(suml > m){
            suml -= a[i]-a[l];l++;
        }
        ans = max(ans,i-l+1);
    }
    cout<<ans<<endl;
    return 0;
}
