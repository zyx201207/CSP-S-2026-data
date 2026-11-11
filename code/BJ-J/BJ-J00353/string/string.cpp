#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
char s[N];
ll n,a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
    }
    ll l=1,r=n+1,cnt=a[1],ans=0,f=1;
    while(r>l){
        ll mx,mn;
        if(f){
            r--;
            mn=min(cnt,a[r]);
            mx=max(cnt,a[r]);
            if(s[r]!=s[l]){
                ans+=mn;
            }
            cnt=mx-mn;
            if(mx==a[r]){
                f=0;
            }
        }
        else{
            l++;
            mn=min(cnt,a[l]);
            mx=max(cnt,a[l]);
            if(s[r]!=s[l]){
                ans+=mn;
            }
            cnt=mx-mn;
            if(mx==a[l]){
                f=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
