#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=2e5+10;
int n;
ll a[N];
char c[N];
ll ans;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=1,r=n;
    while(l<r){
        if(a[l]==a[r]){
            if(c[l]==c[r]){
                l++,r--;
            }
            else{
                ans+=a[l];
                l++;
                r--;
            }
        }
        else if(a[l]<a[r]){
            ll ls=a[r]-a[l];
            if(c[l]==c[r]){
                a[r]-=ls;
                l++;
            }
            else{
                ans+=a[l];
                a[r]-=a[l];
                l++;
            }
        }
        else{
            ll ls=a[l]-a[r];
            if(c[l]==c[r]){
                a[l]-=ls;
                r--;
            }
            else{
                ans+=a[r];
                a[l]-=a[r];
                r--;
            }
        }
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    solve();
    return 0;
}
