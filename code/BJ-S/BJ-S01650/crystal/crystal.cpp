//I love qyr
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
ll a[500005];
ll s[500005];
bool check(int l,int r){
    ll tmp=1ll*(r-l+1)*a[r]-(0ll+s[r]-s[l-1]);
    return tmp<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int ans=0;
    for(int l=1,r=1;r<=n;r++){
        while(l<r){
            if(!check(l,r)){
                l++;
            }else{
                break;
            }
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
