#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld %c",&a[i],&c[i]);
    }
    ll l=1,r=n,ans=0;
    while(l<=r){
        if(c[l]==c[r]){
            if(a[l]>a[r]){
                a[l]-=a[r];
                r--;
            }
            else if(a[l]<a[r]){
                a[r]-=a[l];
                l++;
            }
            else    l++,r--;
        }
        else{
            if(a[l]>a[r]){
                a[l]-=a[r];
                ans+=a[r];
                r--;
            }
            else if(a[l]<a[r]){
                a[r]-=a[l];
                ans+=a[l];
                l++;
            }
            else    ans+=a[l],l++,r--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
