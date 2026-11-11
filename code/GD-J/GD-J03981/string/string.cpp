#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],ans;
char c[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    int l=1,r=n;
    while(l<r){
        if(c[l]==c[r]){
            if(a[l]==a[r]) l++,r--;
            else if(a[l]<a[r]) a[r]-=a[l],l++;
            else a[l]-=a[r],r--;
        }else{
            if(a[l]==a[r]) ans+=a[l],l++,r--;
            else if(a[l]<a[r]) ans+=a[l],a[r]-=a[l],l++;
            else ans+=a[r],a[l]-=a[r],r--;
        }
    }
    cout<<ans;
    return 0;
}