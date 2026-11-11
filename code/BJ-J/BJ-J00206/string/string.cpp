#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
long long ans;
#define int long long
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    int l=1,r=n,ll=a[1],rr=a[n];
    if(c[l]!=c[r]) ans+=min(ll,rr);
    while(l<r){
        if(rr<=ll){
            r--;
            if(c[r]!=c[l]){
                if(rr+a[r]>ll){
                    ans+=ll-rr;
                }
                else{
                    ans+=a[r];
                }
            }
            rr+=a[r];
        }
        else{
            l++;
            if(c[r]!=c[l]){
                if(ll+a[l]>rr){
                    ans+=rr-ll;
                }
                else{
                    ans+=a[l];
                }
            }
            ll+=a[l];
        }
    }
    cout<<ans<<endl;
    return 0;
}
