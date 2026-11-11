#include<bits/stdc++.h>
#define N 1000050
#define ll long long
#define qck ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
ll n,ans;
ll a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    qck;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
    for(int l=1,r=n;l<r;){
        if(c[l]==c[r]){
            if(a[l]==a[r]) a[l]=a[r]=0,l++,r--;
            else if(a[l]>a[r]) a[l]-=a[r],r--;
            else if(a[l]<a[r]) a[r]-=a[l],l++;
        }else{
            if(a[l]==a[r]) ans+=a[l],a[l]=a[r]=0,l++,r--;
            else if(a[l]>a[r]) ans+=a[r],a[l]-=a[r],r--;
            else if(a[l]<a[r]) ans+=a[l],a[r]-=a[l],l++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}