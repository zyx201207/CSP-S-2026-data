#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,ans;
ll ln1[200010],ln2[200010];
ll a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        ln1[i]=ln1[i-1]+a[i];
    }
    for(int i=n;i>0;i--){
        ln2[i]=ln2[i-1]+a[i];
    }
    ll r=n;
    for(int i=1;i<=r;i++){
        while(a[i]>a[r]){
            if(c[i]!=c[r]){
                ans+=a[r];
            }
            a[i]-=a[r];
            r--;
        }
        if(a[i]<a[r]){
            if(c[i]!=c[r]){
                ans+=a[i];
            }
            a[r]-=a[i];
        }else if(a[i]==a[r]){
            if(c[i]!=c[r]){
                ans+=a[i];
            }
            r--;
        }
    }
    cout<<ans;
    return 0;
}

