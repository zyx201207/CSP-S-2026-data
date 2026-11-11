#include <bits/stdc++.h>
using namespace std;
const int N=2e5+100;
#define ll long long
ll n,a[N],ans=0;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    ll l=1,r=n;
    for(;l<r;){
        if(a[l]<a[r]){
            if(c[l]!=c[r]){
                ans+=a[l];
            }
            a[r]-=a[l];
            l++;
        }else if(a[l]>a[r]){
            if(c[l]!=c[r]){
                ans+=a[r];
            }
            a[l]-=a[r];
            r--;
        }else{
            if(c[l]!=c[r])ans+=a[l];
            l++,r--;
        }
    }
    cout<<ans;
    return 0;
}
