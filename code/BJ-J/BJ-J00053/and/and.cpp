#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans=0;
struct node{
    ll x;
    char s[35];
    ll l;
}a[200005];
int vis[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i].x;
        ll p=a[i].x;
        while(p){
            a[i].l++;
            a[i].s[a[i].l]=(p%2==0?'0':'1');
            p/=2;
        }
    }
    for(int k=31;k>=1;k--){
        ll p=0;
        for(int i=1;i<=n;i++){
            if(vis[i]==0&&k<=a[i].l){
                p+=a[i].s[k]-'0';
            }
        }
        ans*=2;
        if(p>=m){
            ans++;
            for(int i=1;i<=n;i++){
                if(k>a[i].l||a[i].s[k]=='0')vis[i]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
