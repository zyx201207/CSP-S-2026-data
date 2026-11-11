#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
int n;
ll a[N],s[N];
ll ans;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        if(s[i]>=s[n]/2){
            ll now=s[n]-s[i-1];
            while(now>max((s[n]+1)/2,s[n]-s[i-1]-a[i])){
                int t=lower_bound(s+1,s+1+n,now)-s;
                if(c[t]!=c[i]){
                    if(s[t-1]<max((s[n]+1)/2,s[n]-s[i-1]-a[i])){
                        ans+=now-max((s[n]+1)/2,s[n]-s[i-1]-a[i]);
                        break;
                    }
                    else{
                        ans+=now-s[t-1];
                        now=s[t-1];
                    }
                }
                else{
                    if(s[t-1]<=max((s[n]+1)/2,s[n]-s[i-1]-a[i])) break;
                    else now=s[t-1];
                }
            }
            break;
        }
        ll now=s[n]-s[i-1];
        while(now>s[n]-s[i-1]-a[i]){
            int t=lower_bound(s+1,s+1+n,now)-s;
            if(c[t]!=c[i]){
                if(s[t-1]<s[n]-s[i-1]-a[i]){
                    ans+=now-s[n]+s[i-1]+a[i];
                    break;
                }
                else{
                    ans+=now-s[t-1];
                    now=s[t-1];
                }
            }
            else{
                if(s[t-1]<=s[n]-s[i-1]-a[i]) break;
                else now=s[t-1];
            }
        }
    }
    cout << ans;
    return 0;
}
